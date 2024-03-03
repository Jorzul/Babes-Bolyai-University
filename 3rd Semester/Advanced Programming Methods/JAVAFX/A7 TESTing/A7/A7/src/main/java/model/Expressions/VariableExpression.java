package model.Expressions;

import model.ADT.MyIDictionary;
import model.Types.Type;
import model.Values.Value;

public class VariableExpression implements Expression {
    public String id;

    public VariableExpression(String id) {
        this.id = id;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIDictionary<Integer, Value> hp) {
        return tbl.lookUp(id);
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) { return typeEnv.lookUp(id); }

    @Override
    public String toString(){
        return id;
    }
}
