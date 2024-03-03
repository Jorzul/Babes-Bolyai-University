package repository;

import model.Item;
import repository.IRepository;

public class Repository implements IRepository {
    private Item[] items = null;
    private int size;
    public Repository(){
        items = new Item[5];
        size = 0;
    }
    public void add(Item item)
    {
        // if size == items.length
        if (this.size < 5)
            items[this.size++] = item;
        else
            System.out.println("Max Capacity.");
    }
    public void remove(Item item)
    {
        int pos = 0;
        for (Item i : items)
        {
            if (i == item)
            {
                while (pos < this.size)
                {
                    items[pos] = items[pos+1];
                    pos++;
                }
                this.size--;
                break;
            }
            //System.out.println(pos);
            pos++;
        }
    }
    public Item[] all()
    {
        return items;
    }
}
