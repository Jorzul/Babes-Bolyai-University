package model.Expressions;

import model.ADT.MyIDictionary;
import model.Exceptions.NonBooleanException;
import model.Exceptions.NonIntegerException;
import model.Types.BoolType;
import model.Types.IntType;
import model.Types.Type;
import model.Values.BoolValue;
import model.Values.Value;

public class LogicalExpression implements Expression {
    public Expression exp1;
    public Expression exp2;
    public enum Operator{And, Or};
    public Operator operator;
    public char operatorString;

    public LogicalExpression(char operator, Expression exp1, Expression exp2) {
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.operatorString = operator;

        switch(operator)
        {
            case '&':
                this.operator = Operator.And;
                break;
            case '|':
                this.operator = Operator.Or;
                break;
        }
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIDictionary<Integer, Value> hp) throws Exception{
        Value v1, v2;
        v1 = exp1.eval(tbl, hp);
        if (!v1.getType().equals(new BoolType()))
            throw new NonBooleanException();

        v2 = exp2.eval(tbl, hp);
        if (!v2.getType().equals(new BoolType()))
            throw new NonBooleanException();

        BoolValue b1 = (BoolValue)v1;
        BoolValue b2 = (BoolValue)v2;
        boolean n1, n2;
        n1 = b1.getValue();
        n2 = b2.getValue();

        switch (operator)
        {
            case And: { return new BoolValue(n1 && n2); }
            case Or: { return new BoolValue(n1 || n2); }
        }

        return null;
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception
    {
        Type tp1 = exp1.typeCheck(typeEnv);
        Type tp2 = exp2.typeCheck(typeEnv);
        if (tp1.equals(new BoolType()))
        {
            if (tp2.equals(new BoolType())) return new BoolType();
            else throw new NonBooleanException();
        }
        else throw new NonBooleanException();
    }

    @Override
    public String toString(){
        return exp1 + " " + operatorString + operatorString + " " + exp2;
    }
}
