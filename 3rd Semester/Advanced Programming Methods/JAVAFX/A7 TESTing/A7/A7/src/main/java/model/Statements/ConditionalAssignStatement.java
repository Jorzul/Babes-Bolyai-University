package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.MyIStack;
import model.ADT.PrgState;
import model.Exceptions.NonIntegerException;
import model.Expressions.Expression;
import model.Types.BoolType;
import model.Types.IntType;
import model.Types.Type;

public class ConditionalAssignStatement implements IStmt{
    String val;
    Expression exp1;
    Expression exp2;
    Expression exp3;

    public ConditionalAssignStatement(String val, Expression ex1, Expression ex2, Expression ex3) {
        this.val = val;
        exp1 = ex1;
        exp2 = ex2;
        exp3 = ex3;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIStack<IStmt> exeStack = state.getExeStack();
        IStmt ifStmt = new IfStatement(
                exp1, new AssignStatement(val, exp2), new AssignStatement(val, exp3)
        );
        exeStack.push(ifStmt);

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type typeVal = typeEnv.lookUp(val);
        Type type1 = exp1.typeCheck(typeEnv);
        Type type2 = exp2.typeCheck(typeEnv);
        Type type3 = exp3.typeCheck(typeEnv);

        if (type1.equals(new BoolType()) && type2.equals(typeVal) && type3.equals(typeVal))
            return typeEnv;
        else
            throw new NonIntegerException();
    }

    @Override
    public String toString() {
        return val + "=" + exp1 + "?" + exp2 + ":" + exp3;
    }
}
