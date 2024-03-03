package model.Statements;

import model.ADT.*;
import model.Exceptions.DeclarationException;
import model.Exceptions.InvalidTypeException;
import model.Types.BoolType;
import model.Types.IntType;
import model.Types.Type;
import model.Values.BoolValue;
import model.Values.IntValue;
import model.Values.RefValue;
import model.Values.Value;

public class VariableDeclarationStatement implements IStmt {
    public String name;
    public Type type;

    public VariableDeclarationStatement(String name, Type type){
        this.name = name;
        this.type = type;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIDictionary<String,Value> symTbl = state.getSymTable();
        if (symTbl.isDefined(name))
            throw new DeclarationException();

        Value val = type.defaultValue();

        symTbl.put(name, val);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        typeEnv.put(name, type);
        return typeEnv;
    }

    @Override
    public String toString() { return "(" + name + ":=" + type + ")"; }
}
