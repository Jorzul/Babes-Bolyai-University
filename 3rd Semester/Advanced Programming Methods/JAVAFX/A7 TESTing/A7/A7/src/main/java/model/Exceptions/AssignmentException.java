package model.Exceptions;

public class AssignmentException extends Exception{
    public AssignmentException() { super("Assignment: right hand side and left hand side have different types"); }
}
