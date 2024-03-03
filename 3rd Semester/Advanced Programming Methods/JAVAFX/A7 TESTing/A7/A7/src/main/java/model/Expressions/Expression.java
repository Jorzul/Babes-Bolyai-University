package model.Expressions;

import model.ADT.MyIDictionary;
import model.Types.Type;
import model.Values.Value;

public interface Expression {
    Value eval(MyIDictionary<String, Value> tbl, MyIDictionary<Integer, Value> hp) throws Exception;
    Type typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception;
}
