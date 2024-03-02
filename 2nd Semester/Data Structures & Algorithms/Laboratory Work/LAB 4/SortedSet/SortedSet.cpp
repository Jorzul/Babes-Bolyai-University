#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

SortedSet::SortedSet(Relation r) {
	//TODO - Implementation

    for (int i = 0; i <= 100; i++)
        table[i] = nullptr;
    relation = r;
}
// Time Complexity: Theta(100)


bool SortedSet::add(TComp elem) {
	//TODO - Implementation

    if (search(elem))
        return false;

    int index = hash(elem);

    Node* newNode = new Node();
    newNode->data = elem;
    newNode->next = nullptr;

    if (table[index] == nullptr)
    {
        table[index] = newNode;
    } else {
        Node* curr = table[index];
        Node* prev = nullptr;

        while (curr != nullptr && !relation(curr->data, elem)) {
            prev = curr;
            curr = curr->next;
        }

        if (prev == nullptr) {
            newNode->next = table[index];
            table[index] = newNode;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }
    }

    return true;
}
// Time Complexities:
// Best Case: Theta(1), when we want to add on an ascending sorted set an element on a position (hash) and it is the lowest
//                      number on that hash.
// Worst Case: Theta(n), where n is the number of current elements in the set. This happens when on an ascending sorted set
//                          we want to add an element on a position (hash) and it already has elements that are lower than our number.


bool SortedSet::remove(TComp elem) {
	//TODO - Implementation
	int index = hash(elem);

    Node* curr = table[index];
    Node* prev = nullptr;

    while (curr != nullptr && curr->data != elem)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        return false;
    }

    if (prev == nullptr)
    {
        table[index] = curr->next;
    } else {
        prev->next = curr->next;
    }

    delete curr;
    return true;
}
// Time Complexities:
// Best Case: Theta(1), when the element that we want to delete is the lowest element in that position (hash).
// Worst Case: Theta(n), where n is the number of current elements in the set. This happens when we do not have the element
//                      that we want to delete in the list


bool SortedSet::search(TComp elem) const {
	//TODO - Implementation
    int index = hash(elem);

    Node* curr = table[index];

    while (curr != nullptr && curr->data != elem)
        curr = curr->next;

    return (curr != nullptr);
}
// Time Complexities:
// Best Case: Theta(1), In an ascending sorted set, when we want to search for an element on a position, and that
//                      element is the lowest from that position.
// Worst Case: Theta(n), where n is the number of elements in the set. This happens when we want to search for an element
//                          in a position and that element is the biggest from that position.


int SortedSet::size() const {
	//TODO - Implementation
	int index = 0;
    for (int i = 0; i <= 100; i++)
        if (table[i] != nullptr)
            index++;
    return index;
}
// Time Complexity: Theta(100), we count every element there is.


bool SortedSet::isEmpty() const {
	//TODO - Implementation
	for (int i = 0; i <= 100; i++)
        if (table[i] != nullptr)
            return false;
    return true;
}
// Time Complexities:
// Best Case: Theta(1), if there exists an element on the position 0 (That's where we start).
// Worst Case: Theta(100), if the list is empty.


bool SortedSet::isSubsetOf(SortedSet &s) const {
    for (int i = 0; i < 100; i++)
    {
        if (table[i] != nullptr)
        {
            if (!s.search(table[i]->data))
            {
                return false;
            }
        }
    }
    return true;
}
// Time Complexity:
// Best Case: Theta(1), if the first element from the current set is not part of the set s.
// Worst Case: Theta(m+n*n_s), where n is the number of elements in the current set. This happens when the current set
//                          is a subset of the set s.


SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}
// Time Complexity: Theta(1)


SortedSet::~SortedSet() {
	//TODO - Implementation
    for (int i = 0; i < 100; i++)
        delete[] table[i];
}
// Time Complexity: Theta(100)


