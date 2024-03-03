package model.Expressions;

import model.ADT.MyIDictionary;
import model.Exceptions.NonIntegerException;
import model.Types.IntType;
import model.Types.Type;
import model.Values.IntValue;
import model.Values.Value;

public class MULExpression implements Expression{
    Expression exp1;
    Expression exp2;

    public MULExpression(Expression ex1, Expression ex2) {
        this.exp1 = ex1;
        this.exp2 = ex2;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIDictionary<Integer, Value> hp) throws Exception {
        Value v1, v2;
        v1 = exp1.eval(tbl, hp);
        if (!v1.getType().equals(new IntType()))
            throw new NonIntegerException();

        v2 = exp2.eval(tbl, hp);
        if (!v2.getType().equals(new IntType()))
            throw new NonIntegerException();

        IntValue i1 = (IntValue)v1;
        IntValue i2 = (IntValue)v2;
        int n1, n2;
        n1 = i1.getValue();
        n2 = i2.getValue();

        return new IntValue((n1*n2)-(n1+n2));
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type tp1 = exp1.typeCheck(typeEnv);
        Type tp2 = exp2.typeCheck(typeEnv);
        if (tp1.equals(new IntType()))
        {
            if (tp2.equals(new IntType())) return new IntType();
            else throw new NonIntegerException();
        }
        else throw new NonIntegerException();
    }

    @Override
    public String toString() {
        return "MUL(" + this.exp1 + "," + this.exp2 + ")";
    }
}
