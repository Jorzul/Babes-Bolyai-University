package model.ADT;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MyDictionary<K,V> implements MyIDictionary<K,V> {
    private Map<K,V> map;

    public MyDictionary() {
        map = new HashMap<K,V>();
    }

    public MyDictionary(MyIDictionary<K, V> dict) { map=dict.getContent(); }

    @Override
    public void put(K k, V v) {
        map.put(k,v);
    }

    @Override
    public void remove(K k) { map.remove(k); }

    @Override
    public boolean isDefined(K k) {
        return map.get(k) != null;
    }

    @Override
    public V lookUp(K k) {
        return map.get(k);
    }

    @Override
    public String toString() {
        return "MyDictionary{" +
                "map=" + map +
                '}';
    }

    @Override
    public Set<K> getKeys() { return map.keySet(); }

    @Override
    public Integer getLength() { return map.size(); }

    @Override
    public Map<K, V> getContent() {
        return map;
    }

    @Override
    public void setContent(Map<K, V> map) {
        this.map = map;
    }
}
