package model.ADT;

import model.Values.Value;

public class SymTableEntry {
    private final String varname;
    private final Value value;

    public SymTableEntry(String varname, Value value){
        this.varname = varname;
        this.value = value;
    }

    public String getVarname(){
        return varname;
    }

    public Value getValue(){
        return value;
    }
}
