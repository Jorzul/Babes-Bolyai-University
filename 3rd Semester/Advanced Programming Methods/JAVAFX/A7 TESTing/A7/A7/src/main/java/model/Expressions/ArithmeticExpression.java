package model.Expressions;

import model.Exceptions.DivisionException;
import model.ADT.MyIDictionary;
import model.Exceptions.InvalidTypeException;
import model.Exceptions.NonIntegerException;
import model.Types.IntType;
import model.Types.Type;
import model.Values.IntValue;
import model.Values.Value;

public class ArithmeticExpression implements Expression{
    public Expression exp1;
    public Expression exp2;
    public enum Operator{Addition, Subtraction, Multiplication, Division};
    public Operator operator;
    public char operatorString;

    public ArithmeticExpression(char operator, Expression exp1, Expression exp2) {
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.operatorString = operator;

        switch(operator)
        {
            case '+':
                this.operator = Operator.Addition;
                break;
            case '-':
                this.operator = Operator.Subtraction;
                break;
            case '*':
                this.operator = Operator.Multiplication;
                break;
            case '/':
                this.operator = Operator.Division;
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
            case Addition: { return new IntValue(n1 + n2); }
            case Subtraction: { return new IntValue(n1 - n2); }
            case Multiplication: { return new IntValue(n1 * n2); }
            case Division: {
                if (n2 == 0)
                    throw new DivisionException();
                return new IntValue(n1 / n2);
            }
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
            if (tp2.equals(new IntType())) return new IntType();
            else throw new NonIntegerException();
        }
        else throw new NonIntegerException();
    }

    @Override
    public String toString(){
        return exp1 + " " + operatorString + " " + exp2;
    }
}
