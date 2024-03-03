package model.Expressions;

import model.ADT.MyIDictionary;
import model.Types.Type;
import model.Values.Value;

public class ValueExpression implements Expression {
    public Value v;

    public ValueExpression(Value v) {
        this.v = v;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIDictionary<Integer, Value> hp) {
        return v;
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) { return v.getType(); }

    @Override
    public String toString(){
        return v.toString();
    }
}
