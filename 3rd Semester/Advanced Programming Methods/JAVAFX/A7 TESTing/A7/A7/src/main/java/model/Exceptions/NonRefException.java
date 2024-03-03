package model.Exceptions;

public class NonRefException extends Exception{
    public NonRefException(){
        super("Operand is not a ref type!");
    }
}
