package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.PrgState;
import model.Exceptions.DeclarationException;
import model.Exceptions.NonStringException;
import model.Expressions.Expression;
import model.Types.StringType;
import model.Types.Type;
import model.Values.StringValue;
import model.Values.Value;

import java.io.BufferedReader;

public class CloseRFileStatement implements IStmt{
    Expression exp;

    public CloseRFileStatement(Expression exp){
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyIDictionary<Integer, Value> heap = state.getHeap();
        Value expVal = exp.eval(symTbl, heap);
        if (!expVal.equals(new StringValue()))
            throw new NonStringException();

        String fileName = ((StringValue)expVal).getValue();
        MyIDictionary<String, BufferedReader> fileTable = state.getFileTable();
        if (!fileTable.isDefined(fileName))
            throw new DeclarationException();

        BufferedReader file = fileTable.lookUp(fileName);
        file.close();
        fileTable.remove(fileName);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type expType = exp.typeCheck(typeEnv);
        if (expType.equals(new StringType())) return typeEnv;
        else throw new NonStringException();
    }

    @Override
    public String toString() { return "closeRFile(" + exp.toString() + ")"; }
}
