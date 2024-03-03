package controller;

import model.ADT.PrgState;
import repository.IRepository;
import model.Values.Value;
import model.Values.RefValue;

import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {
    private IRepository repo;
    private ExecutorService executor;

    public Controller(IRepository repo) { this.repo = repo; }

    public void oneStepForAllPrg(List<PrgState> prgList) throws Exception {
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

    public void allStep() throws Exception {
        repo.clearLog();
        executor = Executors.newFixedThreadPool(2);

        List<PrgState> prgList = removeCompletedPrg(repo.getPrgList());
        while (!prgList.isEmpty()){
            oneStepForAllPrg(prgList);
            prgList = removeCompletedPrg(repo.getPrgList());
        }

        executor.shutdownNow();

        repo.setPrgList(prgList);
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
