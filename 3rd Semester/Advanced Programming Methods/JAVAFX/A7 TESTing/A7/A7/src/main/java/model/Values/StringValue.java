package model.Values;

import model.Types.StringType;
import model.Types.Type;

public class StringValue implements Value{
    public String val;

    public StringValue() { this(""); }
    public StringValue(String v) { val = v; }
    public String getValue() { return val; }
    @Override
    public String toString() { return val; }
    @Override
    public Type getType() { return new StringType(); }
    @Override
    public boolean equals(Object another){
        return another instanceof StringValue;
    }
}
