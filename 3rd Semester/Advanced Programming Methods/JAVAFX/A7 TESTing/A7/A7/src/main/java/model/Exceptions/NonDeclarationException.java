package model.Exceptions;

public class NonDeclarationException extends Exception {
    public NonDeclarationException() { super("The used variable was not declared!"); }
}
