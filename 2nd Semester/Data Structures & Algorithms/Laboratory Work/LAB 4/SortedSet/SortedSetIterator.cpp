#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    current = 0;
    currentNode = nullptr;

	//TODO - Implementation
}
// Time Complexity: Theta(1)


void SortedSetIterator::first() {
	current = 0;
}
// Time Complexity: Theta(1)


void SortedSetIterator::next() {
	if (currentNode != nullptr)
        currentNode = currentNode->next;
}
// Time Complexity: Theta(1)


TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation
	if (currentNode == nullptr) {
        return -1;
    }
    return (currentNode != nullptr);
}
// Time Complexity: Theta(1)

bool SortedSetIterator::valid() const {
	//TODO - Implementation
	return (currentNode != nullptr);
}
// Time Complexity: Theta(1)

