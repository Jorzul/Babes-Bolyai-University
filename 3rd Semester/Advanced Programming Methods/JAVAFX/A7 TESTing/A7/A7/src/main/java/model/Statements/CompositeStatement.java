package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.MyIStack;
import model.ADT.PrgState;
import model.Types.Type;

public class CompositeStatement implements IStmt {
    IStmt first;
    IStmt second;

    public CompositeStatement(IStmt first, IStmt second){
        this.first = first;
        this.second = second;
    }

    @Override
    public PrgState execute(PrgState state) {
        MyIStack<IStmt> stk = state.getExeStack();
        stk.push(second);
        stk.push(first);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        return second.typeCheck(first.typeCheck(typeEnv));
    }

    @Override
    public String toString() { return "(" + first.toString() + ";" + second.toString() + ")"; }
}
