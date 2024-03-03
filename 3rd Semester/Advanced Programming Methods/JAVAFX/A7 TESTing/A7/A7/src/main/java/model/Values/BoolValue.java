package model.Values;

import model.Types.BoolType;
import model.Types.Type;

public class BoolValue implements Value {
    public boolean val;

    public BoolValue() { this(false); }
    public BoolValue(boolean v) { val = v; }
    public boolean getValue() { return val; }
    @Override
    public String toString() { return String.valueOf(val); }
    @Override
    public Type getType() { return new BoolType(); }
    @Override
    public boolean equals(Object another){
        return another instanceof BoolValue;
    }
}
