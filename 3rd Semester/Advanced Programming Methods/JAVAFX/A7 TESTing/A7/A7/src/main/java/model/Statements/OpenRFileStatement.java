package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.PrgState;
import model.Exceptions.DeclarationException;
import model.Exceptions.InvalidTypeException;
import model.Exceptions.NonStringException;
import model.Expressions.Expression;
import model.Types.StringType;
import model.Types.Type;
import model.Values.StringValue;
import model.Values.Value;

import java.io.BufferedReader;
import java.io.FileReader;

public class OpenRFileStatement implements IStmt{
    public Expression exp;

    public OpenRFileStatement(Expression exp){
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyIDictionary<Integer, Value> heap = state.getHeap();
        Value val = exp.eval(symTbl, heap);
        if (!val.equals(new StringValue()))
            throw new InvalidTypeException();
        StringValue stringVal = (StringValue)val;

        MyIDictionary<String, BufferedReader> fileTable = state.getFileTable();
        if (fileTable.isDefined(stringVal.getValue()))
            throw new DeclarationException();

        BufferedReader reader = new BufferedReader(new FileReader(stringVal.getValue()));
        fileTable.put(stringVal.getValue(), reader);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type expType = exp.typeCheck(typeEnv);
        if (expType.equals(new StringType())) return typeEnv;
        else throw new NonStringException();
    }

    @Override
    public String toString() { return "openRFile(" + exp.toString() + ")"; }
}
