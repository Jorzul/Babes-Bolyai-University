#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	//TODO - Implementation

    current = nullptr;
    pushLeftChildren(d.root);
}
// Time Complexity: Theta(1)

void SMMIterator::first(){
	//TODO - Implementation
    current = nullptr;
    stack.clear();
    pushLeftChildren(map.root);

    if (!stack.empty())
        current = stack.back();
}
// Time Complexity: Theta(n) - where n is the number of all left child nodes

void SMMIterator::next(){
	//TODO - Implementation

    if (current == nullptr)
        return;

    if (current->right != nullptr)
        pushLeftChildren(map.root);

    stack.pop_back();
    if (!stack.empty())
        current = stack.back();
    else
        current = nullptr;
}
// Time Complexity: Theta(n) - where n is the number of all left child nodes

bool SMMIterator::valid() const{
	//TODO - Implementation
	return current != nullptr;
}
// Time Complexity: Theta(1)

TElem SMMIterator::getCurrent() const{
	//TODO - Implementation
	if (current != nullptr)
        return make_pair(current->key, current->value);
    else
        return NULL_TELEM;
}
// Time Complexity: Theta(1)

