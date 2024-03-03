package model.Exceptions;

public class NonStringException extends Exception{
    public NonStringException(){
        super("Operand is not a string!");
    }
}
