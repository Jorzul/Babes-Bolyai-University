package com.example.a7;

import controller.GUIManager;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;

import controller.Interpreter;
import javafx.scene.control.cell.PropertyValueFactory;
import model.ADT.*;
import model.Statements.IStmt;
import model.Values.Value;
import repository.IRepository;
import repository.Repository;

import java.io.BufferedReader;
import java.net.URL;
import java.util.*;
import java.util.stream.Collectors;

public class HelloController implements Initializable {
    @FXML private ListView programList;
    @FXML private Label selectedIndex;
    @FXML private Label prgStateCount;
    @FXML private TableView heapTableView;
    @FXML private ListView outList;
    @FXML private ListView fileTableView;
    @FXML private ListView prgStateIdentifiers;
    @FXML private TableView symTableView;
    @FXML private ListView exeStack;

    private GUIManager manager;
    private List<IStmt> programs;
    private int selectedPrgState;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        manager = new GUIManager();

        programs = Interpreter.getPrograms();
        List<String> programsString = programs.stream()
                .map(Object::toString)
                .collect(Collectors.toList());

        ObservableList<String> s = FXCollections.observableArrayList(programsString);
        programList.setItems(s);

        programList.getSelectionModel().select(0);
        setActiveProgram(0);

        TableColumn addressColumn = new TableColumn("Address");
        addressColumn.setCellValueFactory(new PropertyValueFactory<>("address"));
        TableColumn valueColumn = new TableColumn("Value");
        valueColumn.setCellValueFactory(new PropertyValueFactory<>("value"));
        heapTableView.getColumns().setAll(addressColumn, valueColumn);

        selectedPrgState = -1;

        TableColumn varnameColumn = new TableColumn("Variable Name");
        varnameColumn.setCellValueFactory(new PropertyValueFactory<>("varname"));
        TableColumn valueColumn2 = new TableColumn("Value");
        valueColumn2.setCellValueFactory(new PropertyValueFactory<>("value"));
        symTableView.getColumns().setAll(varnameColumn, valueColumn2);
    }

    @FXML
    protected void listViewClicked()
    {
        int selectedInx = programList.getSelectionModel().getSelectedIndex();
        setActiveProgram(selectedInx);
    }

    private void setActiveProgram(int index) {
        selectedIndex.setText("Selected Program: " + index);
        IStmt chosenProgram = programs.get(index);
        PrgState prg = new PrgState(new MyStack<IStmt>(), new MyDictionary<String, Value>(), new MyList<Value>(), new MyDictionary<String, BufferedReader>(), new MyDictionary<Integer, Value>(), chosenProgram);
        IRepository repo = new Repository(prg, "log.txt");

        try {
            manager.setNewRepo(repo);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        clearProgramGUI();
    }

    @FXML
    protected void runOneStep()
    {
        try {
            manager.oneStep();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        updateProgramGUI();
    }

    @FXML
    protected void selectProgram()
    {
        selectedPrgState = Integer.parseInt((String)prgStateIdentifiers.getSelectionModel().getSelectedItem());
        updateProgramGUI();
    }

    private void updateProgramGUI()
    {
        prgStateCount.setText("Current PrgStates: " + manager.getPrgStateCount());

        Map<Integer, Value> heapTable = manager.getHeapTable().getContent();
        ObservableList<HeapTableEntry> heapEntries = FXCollections.observableArrayList();
        for (Map.Entry<Integer, Value> entry : heapTable.entrySet()){
            HeapTableEntry hpEntry = new HeapTableEntry(entry.getKey(), entry.getValue());
            heapEntries.add(hpEntry);
        }
        heapTableView.setItems(heapEntries);

        List<Value> out = manager.getOut().getOutput();
        List<String> outString = out.stream().map(Object::toString).collect(Collectors.toList());
        ObservableList<String> outObservable = FXCollections.observableArrayList(outString);
        outList.setItems(outObservable);

        List<String> fileTable = manager.getFileTable().getKeys().stream().toList();
        ObservableList<String> fileTableObservable = FXCollections.observableArrayList(fileTable);
        fileTableView.setItems(fileTableObservable);

        List<String> programIDs = manager.getProgramIDs();
        ObservableList<String> programIDsObservable = FXCollections.observableArrayList(programIDs);
        prgStateIdentifiers.setItems(programIDsObservable);

        if (!programIDs.contains(String.valueOf(selectedPrgState))) selectedPrgState = -1;

        if (selectedPrgState != -1) {
            Map<String, Value> symTable = manager.getSymTable(selectedPrgState).getContent();
            ObservableList<SymTableEntry> symEntries = FXCollections.observableArrayList();
            for (Map.Entry<String, Value> entry : symTable.entrySet()){
                SymTableEntry stEntry = new SymTableEntry(entry.getKey(), entry.getValue());
                symEntries.add(stEntry);
            }
            symTableView.setItems(symEntries);

            List<IStmt> exeStackList = manager.getExeStack(selectedPrgState).getReversed();
            List<String> exeStackString = exeStackList.stream().map(Object::toString).toList();
            ObservableList<String> exeStackObservable = FXCollections.observableArrayList(exeStackString);
            exeStack.setItems(exeStackObservable);
        }
        else{
            symTableView.getItems().clear();
            exeStack.getItems().clear();
        }
    }

    private void clearProgramGUI()
    {
        heapTableView.getItems().clear();
        outList.getItems().clear();
        fileTableView.getItems().clear();
        prgStateIdentifiers.getItems().clear();

        selectedPrgState = -1;
        symTableView.getItems().clear();
        exeStack.getItems().clear();
    }
}