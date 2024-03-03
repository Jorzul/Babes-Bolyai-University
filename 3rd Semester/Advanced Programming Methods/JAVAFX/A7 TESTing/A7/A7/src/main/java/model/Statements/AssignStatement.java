package model.Statements;

import model.ADT.*;
import model.Exceptions.AssignmentException;
import model.Exceptions.DeclarationException;
import model.Exceptions.MatchingException;
import model.Exceptions.NonDeclarationException;
import model.Expressions.Expression;
import model.Types.Type;
import model.Values.Value;

public class AssignStatement implements IStmt {
    public String id;
    public Expression exp;

    public AssignStatement(String id, Expression exp){
        this.id = id;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIDictionary<String,Value> symTbl = state.getSymTable();
        if (!symTbl.isDefined(id))
            throw new NonDeclarationException();

        MyIDictionary<Integer,Value> heap = state.getHeap();
        Value val = exp.eval(symTbl, heap);
        Type typId = (symTbl.lookUp(id)).getType();
        if (val.getType().equals(typId))
            symTbl.put(id, val);
        else
            throw new MatchingException();

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        Type typeVar = typeEnv.lookUp(id);
        Type typeExp = exp.typeCheck(typeEnv);
        if (typeVar.equals(typeExp))
            return typeEnv;
        else
            throw new AssignmentException();
    }

    @Override
    public String toString() { return id + "=" + exp.toString(); }
}
