#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>

using namespace std;

SortedBag::SortedBag(Relation r) {
	this->relation = r;
	this->nrElements = 0;
    this->capacity = 2;
	this->elements = new TElem[capacity];
}
//Time Complexity: Theta(1)

void SortedBag::add(TComp e) {
	if (this->capacity <= 0)
        throw exception();
    if (this->capacity == this->nrElements)
        resize();
    if (this->nrElements == 0)
    {
        this->elements[nrElements] = e;
        this->nrElements++;
    }
    else
    {
        int index = this->nrElements - 1;
        while (index >= 0 && !this->relation(this->elements[index], e))
        {
            this->elements[index + 1] = this->elements[index];
            index--;
        }
        this->elements[index + 1] = e;
        this->nrElements++;
    }
}
//Best case: Theta(1)
//Worst case: Theta(nrElements)
//Average case: Theta(nrElements)
//Total case: O(nrElements)


bool SortedBag::remove(TComp e) {
	int index = 0;
	bool found = false;
    if (this->nrElements == 0)
        return false;
    else {
        while (index < this->nrElements && !found) {
            if (this->elements[index] == e) {
                found = true;
            } else {
                index++;
            }
        }
        if (found) {
            while(index < nrElements - 1)
            {
                this->elements[index] = this->elements[index + 1];
                index++;
            }
            this->nrElements--;
            return true;
        }
        else
            return false;
    }
}
//Best Case: Theta(1)
//Worst Case: Theta(nrElements)
//Average Case: Theta(nrElements)
//Total Complexity: O(nrElements)


bool SortedBag::search(TComp elem) const {
	int index = 0;
	while (index < this->nrElements)
	{
		if (this->elements[index] == elem)
		{
			return true;
		}
		index++;
	}
	return false;
}
//Time Complexity: Theta(nrElements)


int SortedBag::nrOccurrences(TComp elem) const {
	int index = 0;
	int counter = 0;
	while (index < this->nrElements)
	{
		if (this->elements[index] == elem)
		{
			counter++;
		}
		index++;
	}
    if (counter != 0)
	    return counter;
    else
        return 0;
}
//Time Complexity: Theta(nrElements)


int SortedBag::size() const {
	return this->nrElements;
}
//Time Complexity: Theta(1)


bool SortedBag::isEmpty() const {
	if (nrElements <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Time Complexity: Theta(1)


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}
//Time Complexity: Theta(1)


SortedBag::~SortedBag() {
	delete[] this->elements;
}
//Time Complexity: Theta(1)

void SortedBag::resize()
{
    TComp* newElements;
    newElements = new TComp[this->capacity * 2];
    this->capacity = this->capacity * 2;
    for (int i = 0; i < this->nrElements; i++)
    {
        newElements[i] = this->elements[i];
    }
    delete[] this->elements;
    this->elements = newElements;
}
//Time Complexity: Theta(nrElements)

void SortedBag::addAll(const SortedBag& b)
{
    int index = 0;
    while (index < b.nrElements)
    {
        add(b.elements[index]);
        index++;
    }
}
//Best Case Complexity: Theta(b.nrElements)
//Worst Case Complexity: Theta(b.nrElements * nrElements)
