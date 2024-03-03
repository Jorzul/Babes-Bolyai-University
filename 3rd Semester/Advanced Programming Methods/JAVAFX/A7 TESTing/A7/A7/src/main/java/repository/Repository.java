package repository;

import model.ADT.PrgState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.nio.file.InvalidPathException;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Repository implements IRepository {
    List<PrgState> repo;
    String logFilePath;

    public Repository(PrgState prg, String logFile) {
        this.repo = new LinkedList<PrgState>();
        this.add(prg);
        this.logFilePath = logFile;
    }
    @Override
    public void add(PrgState e){
        repo.add(e);
    }
    @Override
    public void logPrgStateExec(PrgState prg) throws Exception {
        Writer logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
        logFile.append(prg.toString());
        logFile.append("\n-------------------------\n");
        logFile.close();
    }
    @Override
    public void clearLog() throws Exception {
        Writer logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, false)));
        logFile.write("");
        logFile.close();
    }

    @Override
    public List<PrgState> getPrgList() {
        return repo;
    }

    @Override
    public void setPrgList(List<PrgState> list) {
        this.repo = list;
    }

    @Override
    public String toString() {
        return "Repository{" +
                "repo=" + repo +
                '}';
    }

    private boolean isPathValid(String path){
        try {
            Paths.get(path);
        } catch (InvalidPathException | NullPointerException ex) {
            return false;
        }
        return true;
    }
}
