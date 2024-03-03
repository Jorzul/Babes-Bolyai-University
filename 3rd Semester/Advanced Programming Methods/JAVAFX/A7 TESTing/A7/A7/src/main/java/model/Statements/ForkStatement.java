package model.Statements;

import model.ADT.*;
import model.Types.Type;
import model.Values.Value;

import java.io.BufferedReader;
import java.util.Map;

public class ForkStatement implements IStmt{
    IStmt stmt;

    public ForkStatement(IStmt stmt)
    {
        this.stmt = stmt;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyStack<IStmt> newExeStack = new MyStack<>();

        MyIDictionary<String, Value> newSymTbl = new MyDictionary<String, Value>();
        Map<String, Value> map = state.getSymTable().getContent();
        for (String s: map.keySet()){
            newSymTbl.put(s, map.get(s));
        }
        //newSymTbl.setContent(state.getSymTable().getContent());

        return new PrgState(newExeStack, newSymTbl, state.getOut(), state.getFileTable(), state.getHeap(), stmt);
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        stmt.typeCheck(new MyDictionary<>(typeEnv));
        return typeEnv;
    }

    @Override
    public String toString() { return "fork(" + stmt.toString() + ")"; }
}
