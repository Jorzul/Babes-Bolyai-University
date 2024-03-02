#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {

    this->capacity = 0;
    this->relation = r;

    elements = new Node[capacity];

    elements[0].prev = 0;
    elements[0].next = 0;
    head = 0;
    tail = 0;
    list_size = 0;
}
//Time Complexity: Theta(1)

int SortedIndexedList::size() const {
	return list_size;
}
//Time Complexity: Theta(1)

bool SortedIndexedList::isEmpty() const {
	if (list_size == 0)
        return true;
    else
	    return false;
}
//Time Complexity: Theta(1)

TComp SortedIndexedList::getElement(int i) const{
    if (i == 0 && list_size == 0)
        throw exception();
    else
        for (int j = 0; j <= list_size; j++)
            if (i == j)
                return elements[i].data;

    throw exception();
}
// Base case: Theta(1)
// Worst case: Theta(nr of elements)
// Average case: Theta(nr of elements)

TComp SortedIndexedList::remove(int i) {
	TComp deleted_elem;

    if (list_size > 0 && i >= 0 && i <= list_size) {

        if (i == head) {
            deleted_elem = elements[i].data;
            head = elements[i].next;
            deallocate(i);
            list_size--;
            return deleted_elem;

        } else if (i == tail) {
            deleted_elem = elements[i].data;
            tail = elements[i].prev;
            deallocate(i);
            list_size--;
            return deleted_elem;

        } else {
            deleted_elem = elements[elements[i].prev].next;
            elements[elements[i].prev].next = elements[i].next;
            deallocate(i);
            list_size--;
            return deleted_elem;
        }
    } else
        throw exception();
}
// Base case: Theta(1)
// Worst case: Theta(nr of elements)
// Average case: Theta(nr of elements)


int SortedIndexedList::search(TComp e) const {
	if (list_size == 0) {
        return -1;

    } else if (list_size == 1) {
        return 0;

    } else {
        for (int i = 0; i <= list_size; i++)
        {
            if (elements[i].data == e)
                return i;
        }
    }

    return -1;
}
// Base case: Theta(1)
// Worst case: Theta(nr of elements)
// Average case: Theta(nr of elements)

void SortedIndexedList::add(TComp e) {
	int p = head;
    int prev = -1;

    while (p != 0 && relation(elements[p].data, e)) {
        prev = p;
        p = elements[p].next;
    }

    int new_pos = allocate();
    elements[new_pos].data = e;
    elements[new_pos].next = p;
    elements[new_pos].prev = prev;

    if (prev == -1) {
        head = new_pos;
    } else {
        elements[prev].next = new_pos;
    }

    if (p == -1) {
        tail = new_pos;
    } else {
        elements[p].prev = new_pos;
    }
    list_size++;
}
// Base case: Theta(1)
// Worst case: Theta(nr of elements)
// Average case: Theta(nr of elements)

ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}
//Time Complexity: Theta(1)

//destructor
SortedIndexedList::~SortedIndexedList() {
    delete elements;
}
//Time Complexity: Theta(1)
