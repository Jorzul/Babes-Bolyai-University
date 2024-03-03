package model.Expressions;

import model.ADT.MyIDictionary;
import model.Exceptions.InvalidAddressException;
import model.Exceptions.NonRefException;
import model.Types.RefType;
import model.Types.Type;
import model.Values.RefValue;
import model.Values.Value;

public class HeapReadingExpression implements Expression{
    Expression exp;

    public HeapReadingExpression(Expression exp){
        this.exp = exp;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIDictionary<Integer, Value> hp) throws Exception {
        Value val = exp.eval(tbl, hp);
        if (!val.equals(new RefValue()))
            throw new NonRefException();

        RefValue refVal = (RefValue)val;
        int address = refVal.address;
        if (!hp.isDefined(address))
            throw new InvalidAddressException();

        return hp.lookUp(address);
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type typ = exp.typeCheck(typeEnv);

        if (typ instanceof RefType ref) return ref.getInner();
        else throw new NonRefException();
    }

    @Override
    public String toString(){
        return "rH(" + exp.toString() + ")";
    }
}
