#pragma once

#include "SortedMultiMap.h"


class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

	//TODO - Representation
    Node* current;
    std::vector<Node*> stack;

    // Helper function to push all left child nodes onto the stack
    void pushLeftChildren(Node* node) {
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }
    }

public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

