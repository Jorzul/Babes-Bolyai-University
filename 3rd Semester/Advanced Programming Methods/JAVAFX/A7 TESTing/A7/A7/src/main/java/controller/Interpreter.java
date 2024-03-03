package controller;

import model.ADT.*;
import model.Expressions.*;
import model.Statements.*;
import model.Types.*;
import model.Values.*;

import java.util.LinkedList;
import java.util.List;

public class Interpreter {
    public static List<IStmt> getPrograms()
    {
        List<IStmt> programList = new LinkedList<>();

        IStmt example1 = new CompositeStatement(
                new VariableDeclarationStatement("v",new IntType()),
                new CompositeStatement(
                        new AssignStatement("v",new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))
                )
        );
        try {
            example1.typeCheck(new MyDictionary<String, Type>());
            programList.add(example1);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt example2 = new CompositeStatement(
                new VariableDeclarationStatement("a",new IntType()),
                new CompositeStatement(
                        new VariableDeclarationStatement("b",new IntType()),
                        new CompositeStatement(
                                new AssignStatement("a", new ArithmeticExpression('+',new ValueExpression(new IntValue(2)),new ArithmeticExpression('*',new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompositeStatement(
                                        new AssignStatement("b",new ArithmeticExpression('+',new VariableExpression("a"), new ValueExpression(new IntValue(1)))),
                                        new PrintStatement(new VariableExpression("b"))
                                )
                        )
                )
        );
        try {
            example2.typeCheck(new MyDictionary<String, Type>());
            programList.add(example2);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        IStmt example3 = new CompositeStatement(
                new VariableDeclarationStatement("a",new BoolType()),
                new CompositeStatement(
                        new VariableDeclarationStatement("v", new IntType()),
                        new CompositeStatement(
                                new AssignStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompositeStatement(
                                        new IfStatement(new VariableExpression("a"),new AssignStatement("v",new ValueExpression(new IntValue(2))), new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))
                                )
                        )
                )
        );
        try {
            example3.typeCheck(new MyDictionary<String, Type>());
            programList.add(example3);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt example4 = new CompositeStatement(
                new VariableDeclarationStatement("a", new BoolType()),
                new CompositeStatement(
                        new VariableDeclarationStatement("b", new BoolType()),
                        new CompositeStatement(
                                new AssignStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompositeStatement(
                                        new AssignStatement("b", new ValueExpression(new BoolValue(false))),
                                        new PrintStatement(new LogicalExpression('|', new VariableExpression("a"), new VariableExpression("b")))
                                )
                        )
                )
        );
        try {
            example4.typeCheck(new MyDictionary<String, Type>());
            programList.add(example4);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt example5 = new CompositeStatement(
                new VariableDeclarationStatement("varf", new StringType()),
                new CompositeStatement(
                        new VariableDeclarationStatement("varf2", new StringType()),
                        new CompositeStatement(
                                new AssignStatement("varf", new ValueExpression(new StringValue("test.in"))),
                                new CompositeStatement(
                                        new AssignStatement("varf2", new ValueExpression(new StringValue("test2.in"))),
                                        new CompositeStatement(
                                                new OpenRFileStatement(new VariableExpression("varf")),
                                                new CompositeStatement(
                                                        new OpenRFileStatement(new VariableExpression("varf2")),
                                                        new CompositeStatement(
                                                                new VariableDeclarationStatement("varc", new IntType()),
                                                                new CompositeStatement(
                                                                        new ReadFileStatement(new VariableExpression("varf"), "varc"),
                                                                        new CompositeStatement(
                                                                                new PrintStatement(new VariableExpression("varc")),
                                                                                new CompositeStatement(
                                                                                        new ReadFileStatement(new VariableExpression("varf2"), "varc"),
                                                                                        new CompositeStatement(
                                                                                                new PrintStatement(new VariableExpression("varc")),
                                                                                                new CompositeStatement(
                                                                                                        new CloseRFileStatement(new VariableExpression("varf")),
                                                                                                        new CloseRFileStatement(new VariableExpression("varf2"))
                                                                                                )
                                                                                        )
                                                                                )
                                                                        )
                                                                )
                                                        )
                                                )
                                        )
                                )
                        )
                )
        );
        try {
            example5.typeCheck(new MyDictionary<String, Type>());
            programList.add(example5);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt example6 = new CompositeStatement(
                new VariableDeclarationStatement("a", new IntType()),
                new CompositeStatement(
                        new VariableDeclarationStatement("b", new IntType()),
                        new CompositeStatement(
                                new AssignStatement("a", new ValueExpression(new IntValue(25))),
                                new CompositeStatement(
                                        new AssignStatement("b", new ValueExpression(new IntValue(15))),
                                        new PrintStatement(new RelationalExpression("<=", new VariableExpression("a"), new VariableExpression("b")))
                                )
                        )
                )
        );
        try {
            example6.typeCheck(new MyDictionary<String, Type>());
            programList.add(example6);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt example7 = new CompositeStatement(
                new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompositeStatement(
                        new HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompositeStatement(
                                new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompositeStatement(
                                        new HeapAllocationStatement("a", new VariableExpression("v")),
                                        new CompositeStatement(
                                                new PrintStatement(new HeapReadingExpression(new VariableExpression("v"))),
                                                new PrintStatement(new ArithmeticExpression('+', new HeapReadingExpression(new HeapReadingExpression(new VariableExpression("a"))), new ValueExpression(new IntValue(5))))
                                        )
                                )
                        )
                )
        );
        try {
            example7.typeCheck(new MyDictionary<String, Type>());
            programList.add(example7);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt example8 = new CompositeStatement(
                new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompositeStatement(
                        new HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompositeStatement(
                                new PrintStatement(new HeapReadingExpression(new VariableExpression("v"))),
                                new CompositeStatement(
                                        new HeapWritingStatement("v", new ValueExpression(new IntValue(30))),
                                        new PrintStatement(new ArithmeticExpression('+', new HeapReadingExpression(new VariableExpression("v")), new ValueExpression(new IntValue(5))))
                                )
                        )
                )
        );
        try {
            example8.typeCheck(new MyDictionary<String, Type>());
            programList.add(example8);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt example9 = new CompositeStatement(
                new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompositeStatement(
                        new HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompositeStatement(
                                new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompositeStatement(
                                        new NoOperatorStatement(),
                                        new CompositeStatement(
                                                new HeapAllocationStatement("v", new ValueExpression(new IntValue(30))),
                                                new PrintStatement(new HeapReadingExpression(new HeapReadingExpression(new VariableExpression("a"))))
                                        )
                                )
                        )
                )
        );
        try {
            example9.typeCheck(new MyDictionary<String, Type>());
            programList.add(example9);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt example10 = new CompositeStatement(
                new VariableDeclarationStatement("v", new IntType()),
                new CompositeStatement(
                        new AssignStatement("v", new ValueExpression(new IntValue(4))),
                        new CompositeStatement(
                                new WhileStatement(new RelationalExpression(">", new VariableExpression("v"), new ValueExpression(new IntValue(0))), new CompositeStatement(new PrintStatement(new VariableExpression("v")), new AssignStatement("v", new ArithmeticExpression('-', new VariableExpression("v"), new ValueExpression(new IntValue(1)))))),
                                new PrintStatement(new VariableExpression("v"))
                        )
                )
        );
        try {
            example10.typeCheck(new MyDictionary<String, Type>());
            programList.add(example10);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        IStmt example11 = new CompositeStatement(
                new VariableDeclarationStatement("v", new IntType()),
                new CompositeStatement(
                        new VariableDeclarationStatement("a", new RefType(new IntType())),
                        new CompositeStatement(
                                new AssignStatement("v", new ValueExpression(new IntValue(10))),
                                new CompositeStatement(
                                        new HeapAllocationStatement("a", new ValueExpression(new IntValue(22))),
                                        new CompositeStatement(
                                                new ForkStatement(
                                                        new CompositeStatement(
                                                                new HeapAllocationStatement("a", new ValueExpression(new IntValue(30))),
                                                                new CompositeStatement(
                                                                        new AssignStatement("v", new ValueExpression(new IntValue(32))),
                                                                        new CompositeStatement(
                                                                                new PrintStatement(new VariableExpression("v")),
                                                                                new PrintStatement(new HeapReadingExpression(new VariableExpression("a")))
                                                                        )
                                                                )
                                                        )
                                                ),
                                                new CompositeStatement(
                                                        new PrintStatement(new VariableExpression("v")),
                                                        new PrintStatement(new HeapReadingExpression(new VariableExpression("a")))
                                                )
                                        )
                                )
                        )
                )
        );
        try {
            example11.typeCheck(new MyDictionary<String, Type>());
            programList.add(example11);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt example12 = new CompositeStatement(
                new VariableDeclarationStatement("a", new RefType(new IntType())),
                new CompositeStatement(
                        new VariableDeclarationStatement("counter", new IntType()),
                        new WhileStatement(new RelationalExpression("<", new VariableExpression("counter"), new ValueExpression(new IntValue(10))), new CompositeStatement(
                                new ForkStatement(new ForkStatement(new HeapAllocationStatement("a", new VariableExpression("counter")))),
                                new CompositeStatement(
                                        new CompositeStatement(
                                                new NoOperatorStatement(),
                                                new PrintStatement(new HeapReadingExpression(new VariableExpression("a")))),
                                        new AssignStatement("counter", new ArithmeticExpression('+', new VariableExpression("counter"), new ValueExpression(new IntValue(1))))
                                )
                        )
                        )
                )
        );
        try {
            example12.typeCheck(new MyDictionary<String, Type>());
            programList.add(example12);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt exampleSleep = new CompositeStatement(
                new VariableDeclarationStatement("v",new IntType()),
                new CompositeStatement(
                        new AssignStatement("v",new ValueExpression(new IntValue(10))),
                        new CompositeStatement(
                                new ForkStatement(new CompositeStatement(
                                        new AssignStatement("v", new ArithmeticExpression('-', new VariableExpression("v"), new ValueExpression(new IntValue(1)))),
                                        new CompositeStatement(
                                                new AssignStatement("v", new ArithmeticExpression('-', new VariableExpression("v"), new ValueExpression(new IntValue(1)))),
                                                new PrintStatement(new VariableExpression("v"))
                                        )
                                )),
                                new CompositeStatement(
                                        new SleepStatement(10),
                                        new PrintStatement(new ArithmeticExpression('*', new VariableExpression("v"), new ValueExpression(new IntValue(10))))
                                )
                        )
                )
        );
        try {
            exampleSleep.typeCheck(new MyDictionary<String, Type>());
            programList.add(exampleSleep);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt exampleMUL = new CompositeStatement(
                new VariableDeclarationStatement("v1", new IntType()),
                new CompositeStatement(
                        new VariableDeclarationStatement("v2", new IntType()),
                        new CompositeStatement(
                                new AssignStatement("v1", new ValueExpression(new IntValue(2))),
                                new CompositeStatement(
                                        new AssignStatement("v2", new ValueExpression(new IntValue(3))),
                                        new PrintStatement(new MULExpression(new VariableExpression("v1"), new VariableExpression("v2")))
                                )
                        )
                )
        );
        try {
            exampleMUL.typeCheck(new MyDictionary<String, Type>());
            programList.add(exampleMUL);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        IStmt exampleWait = new CompositeStatement(
                new VariableDeclarationStatement("v", new IntType()),
                new CompositeStatement(
                        new AssignStatement("v", new ValueExpression(new IntValue(20))),
                        new CompositeStatement(
                                new WaitStatement(10),
                                new PrintStatement(new ArithmeticExpression('*', new VariableExpression("v"), new ValueExpression(new IntValue(10))))
                        )
                )
        );
        try {
            exampleWait.typeCheck(new MyDictionary<String, Type>());
            programList.add(exampleWait);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        IStmt exampleFor = new CompositeStatement(
                new VariableDeclarationStatement("a", new RefType(new IntType())),
                new CompositeStatement(
                    new HeapAllocationStatement("a", new ValueExpression(new IntValue(20))),
                    new CompositeStatement(
                        new ForStatement("v", new ValueExpression(new IntValue(0)), new ValueExpression(new IntValue(3)), new ArithmeticExpression('+', new VariableExpression("v"), new ValueExpression(new IntValue(1))),
                                new ForkStatement(new CompositeStatement(
                                    new PrintStatement(new VariableExpression("v")),
                                    new AssignStatement("v", new ArithmeticExpression('*', new VariableExpression("v"), new HeapReadingExpression(new VariableExpression("a"))))
                                ))
                        ),
                            new PrintStatement(new HeapReadingExpression(new VariableExpression("a")))
                    )
                )
        );
        programList.add(exampleFor);

        IStmt exampleConditional = new CompositeStatement(
                new VariableDeclarationStatement("a", new RefType(new IntType())),
                new CompositeStatement(
                        new VariableDeclarationStatement("b", new RefType(new IntType())),
                        new CompositeStatement(
                                new VariableDeclarationStatement("v", new IntType()),
                                new CompositeStatement(
                                        new HeapAllocationStatement("a", new ValueExpression(new IntValue(0))),
                                        new CompositeStatement(
                                                new HeapAllocationStatement("b", new ValueExpression(new IntValue(0))),
                                                new CompositeStatement(
                                                        new HeapWritingStatement("a", new ValueExpression(new IntValue(1))),
                                                        new CompositeStatement(
                                                                new HeapWritingStatement("b", new ValueExpression(new IntValue(2))),
                                                                new CompositeStatement(
                                                                        new ConditionalAssignStatement("v", new RelationalExpression("<", new HeapReadingExpression(new VariableExpression("a")), new HeapReadingExpression(new VariableExpression("b"))), new ValueExpression(new IntValue(100)), new ValueExpression(new IntValue(200))),
                                                                        new CompositeStatement(
                                                                                new PrintStatement(new VariableExpression("v")),
                                                                                new CompositeStatement(
                                                                                        new ConditionalAssignStatement("v", new RelationalExpression("<", new HeapReadingExpression(new VariableExpression("a")), new ArithmeticExpression('-', new HeapReadingExpression(new VariableExpression("b")), new ValueExpression(new IntValue(2)))), new ValueExpression(new IntValue(100)), new ValueExpression(new IntValue(200))),
                                                                                        new PrintStatement(new VariableExpression("v"))
                                                                                )
                                                                        )
                                                                )
                                                        )
                                                )
                                        )
                                )
                        )
                )
        );
        try {
            exampleConditional.typeCheck(new MyDictionary<String, Type>());
            programList.add(exampleConditional);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        return programList;
    }
}