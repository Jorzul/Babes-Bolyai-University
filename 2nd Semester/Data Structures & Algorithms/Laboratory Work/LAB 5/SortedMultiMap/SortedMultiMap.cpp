#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <vector>
#include <iostream>

using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
	//TODO - Implementation

    root = nullptr;
    relation = r;
    count = 0;
}
// Time Complexity: Theta(1)

void SortedMultiMap::add(TKey c, TValue v) {
	//TODO - Implementation

    count++;
    root = insert(root, c, v);
}
// Time Complexity:
// Best Case: Theta(1) - when we want to add a smaller number than our root number and there are none smaller or
//                      if we want to add a bigger number than our root number and there are none already.
// Worst Case: Theta(n) - when we want to add the biggest/smallest number, n is the number of elements from the root
//                          to the current biggest or smallest number.

vector<TValue> SortedMultiMap::search(TKey c) const {
	//TODO - Implementation
    vector<TValue> values_vector;
    findValues(root, c, values_vector);

	return values_vector;
}
// Time Complexity:
// Best Case: Theta(1) - when we want to search an element that is smaller than our root number and there are none smaller
//                      numbers than it or if we want to search an element that is bigger than our root number and there
//                      are none others bigger than it.
// Worst Case: Theta(n) - where n is the number of elements from the root to the element we want to search.

bool SortedMultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
    bool removed = false;

    root = _delete(root, c, v, removed);
    if (removed)
        count--;
    return removed;
}
// Time Complexity:
// Best Case: Theta(1) - when we want to remove an element that is smaller than our root number and there are none smaller
//                      numbers than it or if we want to remove an element that is bigger than our root number and there
//                      are none others bigger than it.
// Worst Case: Theta(n) - where n is the number of elements from the root to the element we want to search.

int SortedMultiMap::size() const {
	//TODO - Implementation

	return count;
}
// Time Complexity: Theta(1)

bool SortedMultiMap::isEmpty() const {
	//TODO - Implementation

	if (count > 0)
        return false;
    else
        return true;
}
// Time Complexity: Theta(1)

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}
// Time Complexity: Theta(1)

int SortedMultiMap::addIfNotPresent(SortedMultiMap& smm) {
    int added_count = 0;

//    while (smm.root != nullptr) {
//        if (!key_in_map(root, smm.root->key)) {
//            add(smm.root->key, smm.root->value);
//            added_count++;
//        }
//        cout << added_count;
//        if (smm.root->left != nullptr)
//            smm.root = smm.root->left;
//        else if (smm.root->right != nullptr)
//            smm.root = smm.root->right;
//        else
//            break;
//    }
    go_through_map(smm.root, added_count);

    return added_count;
}
// Time Complexity: Theta(smm1_n * smm2_n)

SortedMultiMap::~SortedMultiMap() {
	//TODO - Implementation

    destroyTree(root);
}
// Time Complexity: Theta(1)
