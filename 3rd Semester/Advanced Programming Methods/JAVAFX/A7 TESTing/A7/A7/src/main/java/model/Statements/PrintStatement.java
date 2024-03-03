package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.MyIList;
import model.ADT.PrgState;
import model.Expressions.Expression;
import model.Types.Type;
import model.Values.Value;

public class PrintStatement implements IStmt {
    public Expression exp;

    public PrintStatement (Expression exp){
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception{
        MyIList<Value> values = state.getOut();
        MyIDictionary<String, Value> dict = state.getSymTable();
        MyIDictionary<Integer, Value> heap = state.getHeap();
        values.add(exp.eval(dict, heap));
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        exp.typeCheck(typeEnv);
        return typeEnv;
    }

    @Override
    public String toString() { return "print(" + exp.toString() + ")"; }
}
