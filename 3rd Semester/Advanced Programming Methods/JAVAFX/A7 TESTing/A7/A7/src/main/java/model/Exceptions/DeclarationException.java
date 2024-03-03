package model.Exceptions;

public class DeclarationException extends Exception{
    public DeclarationException(){ super("The used variable was already declared!"); }
}
