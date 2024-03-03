package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.PrgState;
import model.Exceptions.*;
import model.Expressions.Expression;
import model.Types.IntType;
import model.Types.RefType;
import model.Types.StringType;
import model.Types.Type;
import model.Values.RefValue;
import model.Values.Value;

public class HeapAllocationStatement implements IStmt{
    String varName;
    Expression exp;

    public HeapAllocationStatement(String varName, Expression exp){
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

        RefValue valRef = (RefValue)val;

        MyIDictionary<Integer, Value> heap = state.getHeap();
        Value expVal = exp.eval(symTbl, heap);
        if (!expVal.getType().equals(valRef.locationType))
            throw new InvalidTypeException();

        int newAddress = heap.getLength() + 1;
        heap.put(newAddress, expVal);

        RefValue refVal = new RefValue(newAddress, valRef.locationType);
        symTbl.put(varName, refVal);

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
    public String toString() { return "new(" + varName + "," + exp.toString() + ")"; }
}
