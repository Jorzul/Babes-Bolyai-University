#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->current =0;
}
//Time Complexity: Theta(1)

TComp SortedBagIterator::getCurrent() {
    if (!valid()) {
        throw exception();
    }
    return this->bag.elements[this->current];
}
//Time Complexity: Theta(1)

bool SortedBagIterator::valid() const {
	if (this->current < this->bag.nrElements)
	{
		return true;
	}
	else {
	return false;
	}
}
//Time Complexity: Theta(1)

void SortedBagIterator::next() {
	if (this->current >= this->bag.nrElements) {
		throw exception();
	}
	else {
		this->current++;
	}
}
//Time Complexity: Theta(1)

void SortedBagIterator::first() {
	this->current = 0;
}
//Time Complexity: Theta(1)
