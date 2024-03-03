package gui;

import controller.Controller;
import exceptions.InterpreterException;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import model.expression.*;
import model.programState.ProgramState;
import model.statement.*;
import model.type.IntType;
import model.type.RefType;
import model.utils.*;
import model.value.IntValue;
import repository.IRepository;
import repository.Repository;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ProgramChooserController {
    private ProgramExecutorController programExecutorController;

    public void setProgramExecutorController(ProgramExecutorController programExecutorController) {
        this.programExecutorController = programExecutorController;
    }
    @FXML
    private ListView<IStatement> programsListView;

    @FXML
    private Button displayButton;

    @FXML
    public void initialize() {
        programsListView.setItems(getAllStatements());
        programsListView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
    }

    @FXML
    private void displayProgram() {
        IStatement selectedStatement = programsListView.getSelectionModel().getSelectedItem();
        if (selectedStatement == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error encountered!");
            alert.setContentText("No statement selected!");
            alert.showAndWait();
        } else {
            int id = programsListView.getSelectionModel().getSelectedIndex();
            try {
                selectedStatement.typeCheck(new MyDictionary<>());
                ProgramState programState = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), new MyLatchTable(), selectedStatement);
                IRepository repository = new Repository(programState, "log" + (id + 1) + ".txt");
                Controller controller = new Controller(repository);
                programExecutorController.setController(controller);
            } catch (InterpreterException | IOException exception) {
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error encountered!");
                alert.setContentText(exception.getMessage());
                alert.showAndWait();
            }
        }
    }

    @FXML
    private ObservableList<IStatement> getAllStatements() {
        List<IStatement> allStatements = new ArrayList<>();

        IStatement ex1 = new CompoundStatement(
                new VariableDeclarationStatement("a", new RefType(new IntType())),
                new CompoundStatement(
                        new VariableDeclarationStatement("b", new RefType(new IntType())),
                        new CompoundStatement(
                                new VariableDeclarationStatement("v", new IntType()),
                                new CompoundStatement(
                                        new NewStatement("a", new ValueExpression(new IntValue(0))),
                                        new CompoundStatement(
                                                new NewStatement("b", new ValueExpression(new IntValue(0))),
                                                new CompoundStatement(
                                                        new WriteHeapStatement("a", new ValueExpression(new IntValue(1))),
                                                        new CompoundStatement(
                                                                new WriteHeapStatement("b", new ValueExpression(new IntValue(2))),
                                                                new CompoundStatement(
                                                                        new ConditionalAssignStatement("v", new RelationalExpression("<", new ReadHeapExpression(new VariableExpression("a")), new ReadHeapExpression(new VariableExpression("b"))), new ValueExpression(new IntValue(100)), new ValueExpression(new IntValue(200))),
                                                                        new CompoundStatement(
                                                                                new PrintStatement(new VariableExpression("v")),
                                                                                new CompoundStatement(
                                                                                        new ConditionalAssignStatement("v", new RelationalExpression("<", new ReadHeapExpression(new VariableExpression("a")), new ArithmeticExpression('-', new ReadHeapExpression(new VariableExpression("b")), new ValueExpression(new IntValue(2)))), new ValueExpression(new IntValue(100)), new ValueExpression(new IntValue(200))),
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
        allStatements.add(ex1);

        IStatement ex2 = new CompoundStatement(
                new VariableDeclarationStatement("v1", new RefType(new IntType())),
                new CompoundStatement(
                        new VariableDeclarationStatement("v2", new RefType(new IntType())),
                        new CompoundStatement(
                                new VariableDeclarationStatement("v3", new RefType(new IntType())),
                                new CompoundStatement(
                                        new VariableDeclarationStatement("cnt", new IntType()),
                                        new CompoundStatement(
                                                new NewStatement("v1", new ValueExpression(new IntValue(2))),
                                                new CompoundStatement(
                                                        new NewStatement("v2", new ValueExpression(new IntValue(3))),
                                                        new CompoundStatement(
                                                                new NewStatement("v3", new ValueExpression(new IntValue(4))),
                                                                new CompoundStatement(
                                                                        new NewLatchStatement("cnt", new ReadHeapExpression(new VariableExpression("v2"))),
                                                                        new CompoundStatement(
                                                                                new ForkStatement(
                                                                                        new CompoundStatement(
                                                                                                new WriteHeapStatement("v1", new ArithmeticExpression('*', new ReadHeapExpression(new VariableExpression("v1")), new ValueExpression(new IntValue(10)))),
                                                                                                new CompoundStatement(
                                                                                                        new PrintStatement(new ReadHeapExpression(new VariableExpression("v1"))),
                                                                                                        new CompoundStatement(
                                                                                                                new CountDownStatement("cnt"),
                                                                                                                new ForkStatement(
                                                                                                                        new CompoundStatement(
                                                                                                                                new WriteHeapStatement("v2", new ArithmeticExpression('*', new ReadHeapExpression(new VariableExpression("v2")), new ValueExpression(new IntValue(10)))),
                                                                                                                                new CompoundStatement(
                                                                                                                                        new PrintStatement(new ReadHeapExpression(new VariableExpression("v2"))),
                                                                                                                                        new CompoundStatement(
                                                                                                                                                new CountDownStatement("cnt"),
                                                                                                                                                new ForkStatement(
                                                                                                                                                        new CompoundStatement(
                                                                                                                                                                new WriteHeapStatement("v3", new ArithmeticExpression('*', new ReadHeapExpression(new VariableExpression("v3")), new ValueExpression(new IntValue(10)))),
                                                                                                                                                                new CompoundStatement(
                                                                                                                                                                        new PrintStatement(new ReadHeapExpression(new VariableExpression("v3"))),
                                                                                                                                                                        new CountDownStatement("cnt")
                                                                                                                                                                ))))))))))),
                                                                                                                                                                new CompoundStatement(
                                                                                                                                                                    new AwaitStatement("cnt"),
                                                                                                                                                                    new CompoundStatement(
                                                                                                                                                                            new PrintStatement(new ValueExpression(new IntValue(100))),
                                                                                                                                                                            new CompoundStatement(
                                                                                                                                                                                new CountDownStatement("cnt"),
                                                                                                                                                                                new PrintStatement(new ValueExpression(new IntValue(100)))))))))))))));
        allStatements.add(ex2);
        return FXCollections.observableArrayList(allStatements);
    }
}
