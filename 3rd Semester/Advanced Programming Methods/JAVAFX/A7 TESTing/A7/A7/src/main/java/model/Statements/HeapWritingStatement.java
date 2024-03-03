package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.PrgState;
import model.Exceptions.InvalidAddressException;
import model.Exceptions.InvalidTypeException;
import model.Exceptions.NonDeclarationException;
import model.Exceptions.NonRefException;
import model.Expressions.Expression;
import model.Types.IntType;
import model.Types.RefType;
import model.Types.Type;
import model.Values.RefValue;
import model.Values.Value;

public class HeapWritingStatement implements IStmt{
    String varName;
    Expression exp;
    public HeapWritingStatement(String varName, Expression exp)
    {
        this.varName = varName;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        if (!symTbl.isDefined(varName))
            throw new NonDeclarationException();
        Value val = symTbl.lookUp(varName);
        if (val.getType().equals(new RefType()))
            throw new NonRefException();

        RefValue refVal = (RefValue)val;

        MyIDictionary<Integer, Value> heap = state.getHeap();
        if (!heap.isDefined(refVal.address))
            throw new InvalidAddressException();

        Value valExp = exp.eval(symTbl, heap);
        if (!valExp.getType().equals(refVal.locationType))
            throw new InvalidTypeException();

        heap.put(refVal.address, valExp);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type typeVar = typeEnv.lookUp(varName);
        Type typeExp = exp.typeCheck(typeEnv);
        if (typeVar instanceof RefType)
        {
            RefType valRef = (RefType) typeVar;
            if (typeExp.equals(valRef.getInner())) return typeEnv;
            else throw new InvalidTypeException();
        }
        else throw new NonRefException();
    }

    @Override
    public String toString(){
        return "wH(" + varName + "," + exp.toString() + ")";
    }
}
