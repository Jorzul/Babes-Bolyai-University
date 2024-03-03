package model.Expressions;

import model.ADT.MyIDictionary;
import model.Exceptions.DivisionException;
import model.Exceptions.InvalidTypeException;
import model.Exceptions.NonIntegerException;
import model.Types.BoolType;
import model.Types.IntType;
import model.Types.Type;
import model.Values.BoolValue;
import model.Values.IntValue;
import model.Values.Value;

public class RelationalExpression implements Expression{
    public Expression exp1;
    public Expression exp2;
    public enum Operator{Less, LessEqual, Equal, NotEqual, Greater, GreaterEqual};
    public Operator operator;
    public String operatorString;

    public RelationalExpression(String operator, Expression exp1, Expression exp2){
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.operatorString = operator;

        switch(operator){
            case "<":
                this.operator = Operator.Less;
                break;
            case "<=":
                this.operator = Operator.LessEqual;
                break;
            case "==":
                this.operator = Operator.Equal;
                break;
            case "!=":
                this.operator = Operator.NotEqual;
                break;
            case ">":
                this.operator = Operator.Greater;
                break;
            case ">=":
                this.operator = Operator.GreaterEqual;
                break;
        }
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

        switch (operator)
        {
            case Less: { return new BoolValue(n1 < n2); }
            case LessEqual: { return new BoolValue(n1 <= n2); }
            case Equal: { return new BoolValue(n1 == n2); }
            case NotEqual: { return new BoolValue(n1 != n2); }
            case Greater: { return new BoolValue(n1 > n2); }
            case GreaterEqual: { return new BoolValue(n1 >= n2); }
            default: {
                throw new InvalidTypeException();
            }
        }
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception
    {
        Type tp1 = exp1.typeCheck(typeEnv);
        Type tp2 = exp2.typeCheck(typeEnv);
        if (tp1.equals(new IntType()))
        {
            if (tp2.equals(new IntType())) return new BoolType();
            else throw new NonIntegerException();
        }
        else throw new NonIntegerException();
    }

    @Override
    public String toString(){
        return exp1 + " " + operatorString + " " + exp2;
    }
}
