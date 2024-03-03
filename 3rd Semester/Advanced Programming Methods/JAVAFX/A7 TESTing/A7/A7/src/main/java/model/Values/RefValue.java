package model.Values;

import model.Types.RefType;
import model.Types.Type;

public class RefValue implements Value {
    public int address;
    public Type locationType;

    public RefValue() { this(-1, new RefType()); }
    public RefValue(int address, Type locationType){
        this.address = address;
        this.locationType = locationType;
    }

    @Override
    public String toString() { return "(" + address + "," + locationType.toString() + ")"; }
    @Override
    public Type getType() { return new RefType(locationType); }
    @Override
    public boolean equals(Object another){
        return another instanceof RefValue;
    }
}
