package controller;

import model.ADT.MyIDictionary;
import model.ADT.MyIList;
import model.ADT.MyIStack;
import model.ADT.PrgState;
import model.Statements.IStmt;
import model.Values.RefValue;
import model.Values.Value;
import repository.IRepository;

import java.io.BufferedReader;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class GUIManager {
    private IRepository repo;
    private ExecutorService executor;
    private List<PrgState> prgList;
    private PrgState lastPrgState;
    private boolean running;

    public GUIManager() { running = false; }

    public void setNewRepo(IRepository repository) throws Exception {
        repo = repository;
        repo.clearLog();

        executor = Executors.newFixedThreadPool(2);
        prgList = removeCompletedPrg(repo.getPrgList());
        running = true;
    }

    public void oneStep() throws Exception {
        if (!running) return;

        //System.out.println(prgList.size());
        oneStepForAllPrg(prgList);
        prgList = repo.getPrgList();
        lastPrgState = prgList.get(0);
        prgList = removeCompletedPrg(prgList);

        if (prgList.isEmpty())
        {
            executor.shutdownNow();
            repo.setPrgList(prgList);
            running = false;
        }
        else lastPrgState = prgList.get(0);
    }

    private void oneStepForAllPrg(List<PrgState> prgList) throws Exception {
        for (PrgState prg : prgList)
            repo.logPrgStateExec(prg);

        List<Callable<PrgState>> callList = prgList.stream()
                .map((PrgState p) -> (Callable<PrgState>)(p::oneStep))
                .toList();

        List<PrgState> newPrgList = executor.invokeAll(callList).stream()
                .map(future -> {
                    try {
                        return future.get();
                    } catch (InterruptedException | ExecutionException e) {
                        throw new RuntimeException(e);
                    }
                })
                .filter(p -> p!=null)
                .collect(Collectors.toList());

        prgList.addAll(newPrgList);

        conservativeGarbageCollector(prgList);

        for (PrgState prg : prgList)
            repo.logPrgStateExec(prg);

        repo.setPrgList(prgList);
    }

    public int getPrgStateCount() { return prgList.size(); }
    public MyIDictionary<Integer, Value> getHeapTable() { return lastPrgState.getHeap(); }
    public MyIList<Value> getOut() { return lastPrgState.getOut(); }
    public MyIDictionary<String, BufferedReader> getFileTable() { return lastPrgState.getFileTable(); }
    public List<String> getProgramIDs() {
        List<String> programs = new LinkedList<>();
        for (PrgState prg : prgList){
            programs.add(String.valueOf(prg.getID()));
        }
        return programs;
    }
    private PrgState getPrgByID(int prgID){
        for (PrgState prg : prgList){
            if (prg.getID() == prgID) return prg;
        }
        return null;
    }
    public MyIDictionary<String, Value> getSymTable(int prgID){
        return Objects.requireNonNull(getPrgByID(prgID)).getSymTable();
    }
    public MyIStack<IStmt> getExeStack(int prgID){
        return Objects.requireNonNull(getPrgByID(prgID)).getExeStack();
    }

    List<PrgState> removeCompletedPrg(List<PrgState> inPrgList){
        return inPrgList.stream()
                .filter(PrgState::isNotCompleted)
                .collect(Collectors.toList());
    }

    void conservativeGarbageCollector(List<PrgState> prgList) {
        Map<Integer, Value> newHeap = new HashMap<>();

        for (PrgState prg : prgList) {
            Map<Integer, Value> prgHeap = unsafeGarbageCollector(
                    getAddrFromSymTable(prg.getSymTable().getContent().values(), prg.getHeap().getContent()),
                    prg.getHeap().getContent());

            newHeap.putAll(prgHeap);
        }

        for (PrgState prg : prgList) {
            prg.getHeap().setContent(newHeap);
        }
    }

    Map<Integer,Value> unsafeGarbageCollector(List<Integer> symTableAddr, Map<Integer,Value> heap){
        return heap.entrySet().stream()
                .filter(e->symTableAddr.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    List<Integer> getAddrFromSymTable(Collection<Value> symTableValues, Map<Integer,Value> heap){
        List<RefValue> refValues = symTableValues.stream()
                .filter(v-> v instanceof RefValue)
                .map(v-> (RefValue)v)
                .toList();

        List<Integer> addresses = new LinkedList<>();
        for (RefValue r : refValues)
        {
            int addr = r.address;
            if (!addresses.contains(addr))
                addresses.add(addr);

            Value loop = heap.get(addr);
            while (loop != null && loop.equals(new RefValue()))
            {
                addr = ((RefValue)loop).address;
                loop = heap.get(addr);

                if (!addresses.contains(addr))
                    addresses.add(addr);
            }
        }

        return addresses;
    }
}
