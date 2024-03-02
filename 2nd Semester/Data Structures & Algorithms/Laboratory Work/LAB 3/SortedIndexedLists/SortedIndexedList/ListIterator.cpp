#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
    this->current = 0;
}
//Time Complexity: Theta(1)

void ListIterator::first(){
    this->current = 0;
}
//Time Complexity: Theta(1)

void ListIterator::next(){
	if (this->current >= this->list.list_size)
        throw exception();
    else
        this->current++;
}
//Time Complexity: Theta(1)

bool ListIterator::valid() const{
	if (this->current < this->list.list_size)
        return true;
    else
	    return false;
}
//Time Complexity: Theta(1)

TComp ListIterator::getCurrent() const{
    if (!valid())
        throw exception();

    TComp e = this->list.elements[current].data;
    return e;
}
//Time Complexity: Theta(1)

void ListIterator::jumpForward(int k) {
    if (k <= 0)
        throw exception();

    while (k > 0)
    {
        this->current++;
        k--;
    }

    if (!valid())
        throw exception();
}
//Time Complexity: Theta(k)