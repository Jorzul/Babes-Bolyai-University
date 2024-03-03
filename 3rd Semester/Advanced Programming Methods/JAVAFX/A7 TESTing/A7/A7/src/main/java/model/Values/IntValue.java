package model.Values;

import model.Types.IntType;
import model.Types.Type;

public class IntValue implements Value {
    public int val;

    public IntValue() { this(0); }
    public IntValue(int v) { val = v; }
    public int getValue() { return val; }
    @Override
    public String toString() { return String.valueOf(val); }
    @Override
    public Type getType() { return new IntType(); }
    @Override
    public boolean equals(Object another){
        return another instanceof IntValue;
    }
}
