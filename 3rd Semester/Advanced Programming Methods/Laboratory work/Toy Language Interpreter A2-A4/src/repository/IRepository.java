package repository;

import model.Item;

public interface IRepository {
    void add(Item item);
    void remove(Item item);
    Item[] all();
}
