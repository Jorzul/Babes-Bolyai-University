package model.ADT;

import java.util.Map;
import java.util.Set;

public interface MyIDictionary<K,V> {
    void put(K k, V v);
    void remove(K k);
    boolean isDefined(K k);
    V lookUp(K k);
    Set<K> getKeys();
    Integer getLength();
    Map<K, V> getContent();
    void setContent(Map<K, V> map);
}
