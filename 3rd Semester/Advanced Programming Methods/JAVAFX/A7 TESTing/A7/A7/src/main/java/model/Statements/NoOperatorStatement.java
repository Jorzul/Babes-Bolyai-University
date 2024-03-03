package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.PrgState;
import model.Types.Type;

public class NoOperatorStatement implements IStmt {
    public NoOperatorStatement() {}
    @Override
    public PrgState execute(PrgState state) {
        return null;
    }
    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) { return typeEnv; }
    @Override
    public String toString() { return "NoOp"; }
}
