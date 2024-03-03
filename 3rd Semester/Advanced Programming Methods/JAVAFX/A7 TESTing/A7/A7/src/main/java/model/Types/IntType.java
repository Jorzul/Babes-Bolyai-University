package model.Types;

import model.Values.BoolValue;
import model.Values.IntValue;
import model.Values.Value;

public class IntType implements Type {
    @Override
    public boolean equals(Object another){
        return another instanceof IntType;
    }

    @Override
    public Value defaultValue() { return new IntValue(); }

    @Override
    public String toString() { return "integer";}
}
