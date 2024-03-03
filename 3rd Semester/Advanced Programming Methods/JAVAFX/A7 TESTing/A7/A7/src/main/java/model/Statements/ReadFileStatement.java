package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.PrgState;
import model.Exceptions.DeclarationException;
import model.Exceptions.NonIntegerException;
import model.Exceptions.NonStringException;
import model.Expressions.Expression;
import model.Types.IntType;
import model.Types.StringType;
import model.Types.Type;
import model.Values.IntValue;
import model.Values.StringValue;
import model.Values.Value;

import java.io.BufferedReader;

public class ReadFileStatement implements IStmt{
    Expression exp;
    String var_name;

    public ReadFileStatement(Expression exp, String var_name){
        this.exp = exp;
        this.var_name = var_name;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        if (!symTbl.isDefined(var_name))
            throw new DeclarationException();

        Value val = symTbl.lookUp(var_name);
        if (!val.equals(new IntValue()))
            throw new NonIntegerException();

        MyIDictionary<Integer, Value> heap = state.getHeap();
        Value expVal = exp.eval(symTbl, heap);
        if (!expVal.equals(new StringValue()))
            throw new NonStringException();

        String fileName = ((StringValue)expVal).getValue();
        MyIDictionary<String, BufferedReader> fileTable = state.getFileTable();
        if (!fileTable.isDefined(fileName))
            throw new DeclarationException();

        BufferedReader file = fileTable.lookUp(fileName);
        String line = file.readLine();
        IntValue integerValue = new IntValue();
        if (line != null){
            integerValue = new IntValue(Integer.parseInt(line));
        }
        symTbl.put(var_name, integerValue);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type typeVar = typeEnv.lookUp(var_name);
        Type typeExp = exp.typeCheck(typeEnv);
        if (typeVar.equals(new IntType()))
        {
            if (typeExp.equals(new StringType())) return typeEnv;
            else throw new NonStringException();
        }
        else throw new NonIntegerException();
    }

    @Override
    public String toString() { return "readFile(" + exp.toString() + ";" + var_name + ")"; }
}
