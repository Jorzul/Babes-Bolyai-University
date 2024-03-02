#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

SortedMap::SortedMap(Relation r) {
	this->relation = r;
    this->head = nullptr;
    this->map_size = 0;
}
//Time Complexity: Theta(1)

TValue SortedMap::add(TKey k, TValue v) {
	Node* newNode = new Node(k, v);

    if (!head)
    {
        head = newNode;
        map_size++;

        return NULL_TVALUE;
    }

    Node* current = head;
    int index = this->map_size - 1;
    while (index >= 0) {
        if (current->key == k) {
            current->value = v;
            return v;
        }
        index--;
    }

    current = head;
    index = this->map_size - 1;
    while (index >= 0 && !this->relation(current->key, k)) {
        current = current->next;
        index--;
    }

    if (current == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {

        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    map_size++;
	return NULL_TVALUE;
}
//Best case: Theta(1)
//Worst case: Theta(nr of elements)
//Average case: Theta(nr of elements)
//Total case: O(nr of elements)

TValue SortedMap::search(TKey k) const {
	Node* current = head;
    while (current) {
        if (current->key == k)
            return current->value;
        current = current->next;
    }
    return NULL_TVALUE;
}
//Best case: Theta(1)
//Worst case: Theta(nr of elements)
//Average case: Theta(nr of elements)
//Total case: O(nr of elements)

TValue SortedMap::remove(TKey k) {

	Node* current = head;
    while (current) {
        if (current->key == k) {
            TValue return_value;
            return_value = current->value;
            if (current == head) {
                head = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            map_size--;
            return return_value;
        }
        current = current->next;
    }
	return NULL_TVALUE;
}
//Best Case: Theta(1)
//Worst Case: Theta(nrElements)
//Average Case: Theta(nrElements)
//Total Complexity: O(nrElements)

int SortedMap::size() const {
	return map_size;
}
//Time Complexity: Theta(1)

bool SortedMap::isEmpty() const {
	if (map_size <= 0)
        return true;
	return false;
}
//Time Complexity: Theta(1)

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}
//Time Complexity: Theta(1)

SortedMap::~SortedMap() {
	Node* current = head;
    while (current) {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
}
//Time Complexity: Theta(1)

int SortedMap::addIfNotPresent(SortedMap &sm) {
    Node* current = head;
    int added_pairs = 0;
    int index = this->map_size - 1;
    int index_sm;
    while (index >= 0) {
        Node* current_sm = sm.head;
        index_sm = sm.map_size - 1;
        while (index_sm >= 0)
        {
            if (current->key != current_sm->key)
            {
                TKey sm2_key = current_sm->key;
                TValue sm2_value = current_sm->value;
                add(sm2_key, sm2_value);
                added_pairs++;
            }
            current_sm = current_sm->next;
            index_sm--;
        }
        current = current->next;
        index--;
    }
    return added_pairs;
}
//Best Case: Theta(1)
//Worst Case: Theta(n_of_sm_elements * n_of_sm2_elements)
//Total Case: O(n_of_sm_elements * n_of_sm2_elements)
