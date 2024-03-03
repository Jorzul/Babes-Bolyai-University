package model.ADT;

import model.Exceptions.EmptyStackException;
import model.Statements.IStmt;
import model.Values.BoolValue;
import model.Values.Value;

import java.io.BufferedReader;

public class PrgState{
    static int nextId = 1;
    MyIStack<IStmt> exeStack;
    MyIDictionary<String, Value> symTable;
    MyIList<Value> out;
    MyIDictionary<String, BufferedReader> fileTable;
    MyIDictionary<Integer, Value> heap;
    int id;

    public PrgState(MyIStack<IStmt> stk, MyIDictionary<String,Value> symtbl, MyIList<Value> ot,
            MyIDictionary<String, BufferedReader> ft,
            MyIDictionary<Integer, Value> hp, IStmt prg){
        exeStack=stk;
        symTable=symtbl;
        out = ot;
        fileTable = ft;
        heap = hp;
        id = generateNextID();

        exeStack.push(prg);
    }

    public Boolean isNotCompleted() { return !exeStack.isEmpty(); }

    public static synchronized int generateNextID() { return nextId++; }

    public PrgState oneStep() throws Exception {
        if(exeStack.isEmpty()) throw new EmptyStackException();
        IStmt crtStmt = exeStack.pop();
        return crtStmt.execute(this);
    }

    public int getID() { return id; }
    public MyIStack<IStmt> getExeStack() {
        return exeStack;
    }
    public void setExeStack(MyIStack<IStmt> exeStack) {
        this.exeStack = exeStack;
    }
    public MyIDictionary<String, Value> getSymTable() {
        return symTable;
    }
    public void setSymTable(MyIDictionary<String, Value> symTable) { this.symTable = symTable; }
    public MyIList<Value> getOut() { return out; }
    public void setOut(MyIList<Value> out) {
        this.out = out;
    }
    public MyIDictionary<String, BufferedReader> getFileTable() { return fileTable; }
    public void setFileTable(MyIDictionary<String, BufferedReader> fileTable) { this.fileTable = fileTable; }
    public MyIDictionary<Integer, Value> getHeap() { return heap; }
    public void setHeap(MyIDictionary<Integer, Value> heap) { this.heap = heap; }

    @Override
    public String toString() {
        return "ID: " + id +
                "\nExeStack:\n" + exeStack.getReversed() +
                "\nSymTable:\n" + symTable +
                "\nOut:\n" + out +
                "\nFileTable:\n" + fileTable.getKeys() +
                "\nHeap:\n" + heap;
    }
}
