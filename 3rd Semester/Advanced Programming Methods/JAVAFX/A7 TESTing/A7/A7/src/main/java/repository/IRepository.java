package repository;

import model.ADT.PrgState;

import java.util.List;

public interface IRepository {
    void add(PrgState e);
    void logPrgStateExec(PrgState prg) throws Exception;
    void clearLog() throws Exception;
    List<PrgState> getPrgList();
    void setPrgList(List<PrgState> list);
}
