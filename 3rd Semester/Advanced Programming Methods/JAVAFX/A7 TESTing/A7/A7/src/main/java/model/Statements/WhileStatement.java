package model.Statements;

import model.ADT.MyDictionary;
import model.ADT.MyIDictionary;
import model.ADT.MyIStack;
import model.ADT.PrgState;
import model.Exceptions.NonBooleanException;
import model.Expressions.Expression;
import model.Types.BoolType;
import model.Types.Type;
import model.Values.BoolValue;
import model.Values.Value;

public class WhileStatement implements IStmt{
    Expression exp;
    IStmt stmt;

    public WhileStatement(Expression exp, IStmt stmt){
        this.exp = exp;
        this.stmt = stmt;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception
    {
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyIDictionary<Integer, Value> heap = state.getHeap();
        Value val = exp.eval(symTbl, heap);

        if (!val.equals(new BoolValue()))
            throw new NonBooleanException();

        BoolValue boolVal = (BoolValue)val;
        if (boolVal.getValue())
        {
            MyIStack<IStmt> stk = state.getExeStack();
            stk.push(new WhileStatement(exp, stmt));
            stk.push(stmt);
        }

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type typeExp = exp.typeCheck(typeEnv);
        if (typeExp.equals(new BoolType()))
        {
            stmt.typeCheck(new MyDictionary<>(typeEnv));
            return typeEnv;
        }
        else
            throw new NonBooleanException();
    }

    @Override
    public String toString() { return "while(" + exp.toString() + ")" + stmt; }
}
