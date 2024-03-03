package model.statement;

import exceptions.InterpreterException;
import model.expression.IExpression;
import model.programState.ProgramState;
import model.type.BoolType;
import model.type.Type;
import model.utils.MyIDictionary;
import model.utils.MyIStack;

public class ConditionalAssignStatement implements IStatement{
    String var;
    IExpression exp1;
    IExpression exp2;
    IExpression exp3;

    public ConditionalAssignStatement(String var, IExpression ex1, IExpression ex2, IExpression ex3) {
        this.var = var;
        exp1 = ex1;
        exp2 = ex2;
        exp3 = ex3;
    }

    @Override
    public ProgramState execute(ProgramState state) throws InterpreterException {
        MyIStack<IStatement> exeStack = state.getExeStack();
        IStatement ifStmt = new IfStatement(
                exp1, new AssignStatement(var, exp2), new AssignStatement(var, exp3)
        );
        exeStack.push(ifStmt);

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws InterpreterException {
        Type typeVar = typeEnv.lookUp(var);
        Type type1 = exp1.typeCheck(typeEnv);
        Type type2 = exp2.typeCheck(typeEnv);
        Type type3 = exp3.typeCheck(typeEnv);

        if (type1.equals(new BoolType()) && type2.equals(typeVar) && type3.equals(typeVar))
            return typeEnv;
        else
            throw new InterpreterException();
    }

    @Override
    public IStatement deepCopy() {
        return new ConditionalAssignStatement(var, exp1.deepCopy(), exp2.deepCopy(), exp3.deepCopy());
    }

    @Override
    public String toString() {
        return var + "=" + exp1 + "?" + exp2 + ":" + exp3;
    }
}
