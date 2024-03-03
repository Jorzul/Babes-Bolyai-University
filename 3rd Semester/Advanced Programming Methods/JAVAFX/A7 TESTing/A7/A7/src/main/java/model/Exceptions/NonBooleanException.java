package model.Exceptions;

public class NonBooleanException extends Exception{
    public NonBooleanException(){
        super("Operand is not a boolean!");
    }
}
