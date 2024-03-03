package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.PrgState;
import model.Types.Type;

public interface IStmt {
    PrgState execute(PrgState state) throws Exception;
    MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception;
}