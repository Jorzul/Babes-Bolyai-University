package model.Exceptions;

public class InvalidAddressException extends Exception{
    public InvalidAddressException() { super("The provided address is not valid in the heap!"); }
}
