package model.Statements;

import model.ADT.*;
import model.Exceptions.NonBooleanException;
import model.Expressions.Expression;
import model.Types.BoolType;
import model.Types.Type;
import model.Values.BoolValue;
import model.Values.Value;

public class IfStatement implements IStmt {
    public Expression exp;
    public IStmt thenS;
    public IStmt elseS;

    public IfStatement(Expression exp, IStmt thenS, IStmt elseS){
        this.exp = exp;
        this.thenS = thenS;
        this.elseS = elseS;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIStack<IStmt> stk = state.getExeStack();
        MyIDictionary<Integer, Value> heap = state.getHeap();
        MyIDictionary<String, Value> dict = state.getSymTable();
        Value res = exp.eval(dict, heap);
        if (!res.getType().equals(new BoolType()))
            throw new NonBooleanException();
        else {
            BoolValue val = (BoolValue)res;
            boolean n = val.getValue();
            if (n)
                stk.push(thenS);
            else
                stk.push(elseS);
        }
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type typeExp = exp.typeCheck(typeEnv);
        if (typeExp.equals(new BoolType()))
        {
            thenS.typeCheck(new MyDictionary<>(typeEnv));
            elseS.typeCheck(new MyDictionary<>(typeEnv));
            return typeEnv;
        }
        else
            throw new NonBooleanException();
    }

    @Override
    public String toString() { return "(IF(" + exp.toString() + ")-> THEN(" + thenS.toString() + ")-> ELSE(" + elseS.toString()+"))"; }
}
