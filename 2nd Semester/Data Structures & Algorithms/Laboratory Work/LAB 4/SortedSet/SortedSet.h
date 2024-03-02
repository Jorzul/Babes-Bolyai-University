#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111
class SortedSetIterator;

struct Node {
    TComp data;
    Node* next;
};

class SortedSet {
	friend class SortedSetIterator;
private:
	//TODO - Representation

    Node* table[101];
    Relation relation;

    int hash(const TComp& element) const {
        if (element >= 0)
            return element % 100;
        else
            return (0 - element) % 100;
    }
    // Time Complexity: Theta(1)

public:

	//constructor
	SortedSet(Relation r);

	//adds an element to the sorted set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TComp e);

	
	//removes an element from the sorted set
	//if the element was removed, it returns true, otherwise false
	bool remove(TComp e);

	//checks if an element is in the sorted set
	bool search(TElem elem) const;


	//returns the number of elements from the sorted set
	int size() const;

	//checks if the sorted set is empty
	bool isEmpty() const;

    bool isSubsetOf(SortedSet& s) const;

	//returns an iterator for the sorted set
	SortedSetIterator iterator() const;

	// destructor
	~SortedSet();


};
