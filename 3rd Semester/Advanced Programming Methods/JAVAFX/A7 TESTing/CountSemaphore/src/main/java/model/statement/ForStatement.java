package model.statement;

import exceptions.InterpreterException;
import model.expression.IExpression;
import model.expression.RelationalExpression;
import model.expression.VariableExpression;
import model.programState.ProgramState;
import model.type.IntType;
import model.type.Type;
import model.utils.MyIDictionary;
import model.utils.MyIStack;

public class ForStatement implements IStatement{
    private final String var;
    private final IExpression exp1;
    private final IExpression exp2;
    private final IExpression exp3;
    IStatement stmt;

    public ForStatement(String var, IExpression ex1, IExpression ex2, IExpression ex3, IStatement stmt) {
        this.var = var;
        this.exp1 = ex1;
        this.exp2 = ex2;
        this.exp3 = ex3;
        this.stmt = stmt;
    }

    @Override
    public ProgramState execute(ProgramState state) throws InterpreterException {
        MyIStack<IStatement> exeStack = state.getExeStack();
        IStatement toWhile = new CompoundStatement(
                new VariableDeclarationStatement(var, new IntType()),
                new CompoundStatement(
                        new AssignStatement(var, exp1),
                        new WhileStatement(
                                new RelationalExpression("<", new VariableExpression(var), exp2),
                                new CompoundStatement(stmt, new AssignStatement(var, exp3))
                        )
                )
        );
        exeStack.push(this.deepCopy());
        exeStack.push(toWhile);

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws InterpreterException {
        Type type1 = exp1.typeCheck(typeEnv);
        Type type2 = exp2.typeCheck(typeEnv);
        Type type3 = exp3.typeCheck(typeEnv);

        if (type1.equals(new IntType()) && type2.equals(new IntType()) && type3.equals(new IntType()))
            return typeEnv;
        else
            throw new InterpreterException();
    }

    @Override
    public IStatement deepCopy() {
        return new ForStatement(var, exp1.deepCopy(), exp2.deepCopy(), exp3.deepCopy(), stmt.deepCopy());
    }

    @Override
    public String toString() {
        return "for(" + var + "=" + exp1 + ";" + var + "<" + exp2 + ";" + var + "=" + exp3 + ") {" + stmt + "}";
    }
}
