package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.MyIStack;
import model.ADT.PrgState;
import model.Exceptions.NonIntegerException;
import model.Expressions.Expression;
import model.Expressions.RelationalExpression;
import model.Expressions.VariableExpression;
import model.Types.IntType;
import model.Types.Type;

public class ForStatement implements IStmt{
    private final String var;
    Expression exp1;
    Expression exp2;
    Expression exp3;
    IStmt stmt;

    public ForStatement(String var, Expression ex1, Expression ex2, Expression ex3, IStmt stmt) {
        this.var = var;
        exp1 = ex1;
        exp2 = ex2;
        exp3 = ex3;
        this.stmt = stmt;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIStack<IStmt> exeStack = state.getExeStack();
        IStmt toWhile = new CompositeStatement(
                            new VariableDeclarationStatement(var, new IntType()),
                            new CompositeStatement(
                                new AssignStatement(var, exp1),
                                new WhileStatement(new RelationalExpression("<", new VariableExpression(var), exp2),
                                new CompositeStatement(stmt, new AssignStatement(var, exp3)))
                            )
                        );
        exeStack.push(toWhile);

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type type1 = exp1.typeCheck(typeEnv);
        Type type2 = exp2.typeCheck(typeEnv);
        Type type3 = exp3.typeCheck(typeEnv);

        if (type1.equals(new IntType()) && type2.equals(new IntType()) && type3.equals(new IntType()))
            return typeEnv;
        else
            throw new NonIntegerException();
    }

    @Override
    public String toString() {
        return "for(" + var + "=" + exp1 + ";" + var + "<" + exp2 + ";" + var + "=" + exp3 + ") {" + stmt + "}";
    }
}
