package model.Exceptions;

public class NonIntegerException extends Exception{
    public NonIntegerException(){
        super("Operand is not an integer!");
    }
}
