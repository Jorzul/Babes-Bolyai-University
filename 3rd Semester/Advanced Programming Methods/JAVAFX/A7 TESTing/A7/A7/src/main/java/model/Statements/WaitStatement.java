package model.Statements;

import model.ADT.MyIDictionary;
import model.ADT.PrgState;
import model.Expressions.ValueExpression;
import model.Types.Type;
import model.Values.IntValue;

public class WaitStatement implements IStmt{
    Integer number;

    public WaitStatement(Integer number) {
        this.number = number;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        if (number != 0)
            state.getExeStack().push(new CompositeStatement(new PrintStatement(new ValueExpression(new IntValue(number))), new WaitStatement(number - 1)));
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws Exception {
        return typeEnv;
    }

    @Override
    public String toString() {
        return "Wait(" + number + ")";
    }
}
