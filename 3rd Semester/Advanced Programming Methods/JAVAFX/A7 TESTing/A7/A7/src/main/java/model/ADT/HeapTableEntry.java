package model.ADT;
import model.Values.Value;

public class HeapTableEntry {
    private final Integer address;
    private final Value value;

    public HeapTableEntry(Integer address, Value value){
        this.address = address;
        this.value = value;
    }

    public Integer getAddress(){
        return address;
    }

    public Value getValue(){
        return value;
    }
}
