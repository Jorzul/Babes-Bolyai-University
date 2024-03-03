package model.Exceptions;

public class MatchingException extends Exception {
    public MatchingException() { super("Declared type of variable and type of the assigned expression do not match."); }
}
