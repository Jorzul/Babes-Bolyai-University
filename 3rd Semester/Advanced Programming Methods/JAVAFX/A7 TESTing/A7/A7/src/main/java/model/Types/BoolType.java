package model.Types;

import model.Values.BoolValue;
import model.Values.Value;

public class BoolType implements Type {
    @Override
    public boolean equals(Object another){
        return another instanceof BoolType;
    }

    @Override
    public Value defaultValue() { return new BoolValue(); }

    @Override
    public String toString() { return "boolean";}
}
