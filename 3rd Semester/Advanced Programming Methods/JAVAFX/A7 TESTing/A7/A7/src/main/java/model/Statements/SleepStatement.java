package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.PrgState;
import model.Types.Type;

public class SleepStatement implements IStmt{
    Integer number;

    public SleepStatement(Integer number) {
        this.number = number;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        if (number != 0)
            state.getExeStack().push(new SleepStatement(number - 1));

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        return typeEnv;
    }

    @Override
    public String toString() {
        return "sleep(" + number + ")";
    }
}
