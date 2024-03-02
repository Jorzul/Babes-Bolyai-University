#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
class ListIterator;
typedef int TComp;
typedef bool (*Relation)(TComp, TComp);
#define NULL_TCOMP -11111

class SortedIndexedList {
private:
	friend class ListIterator;
private:
    struct Node {
        TComp data;
        int next;
        int prev;
    };
    Node* elements;
    int head;
    int tail;
    int capacity;
    int list_size;
    Relation relation;

    int allocate() {
        int p = elements[0].next;
        elements[0].next = elements[p].next;
        elements[elements[p].next].prev = 0;
        return p;
    }

    void deallocate(int i) {
        elements[i].next = elements[0].next;
        elements[i].prev = 0;
        elements[0].next = i;
        elements[elements[i].next].prev = i;
    }

public:
	// constructor
    // DONE
	SortedIndexedList(Relation r);

	// returns the size of the list
    // DONE
	int size() const;

	// checks if the list is empty
    // DONE
	bool isEmpty() const;

	// returns an element from a position
	// throws exception if the position is not valid
    // DONE
	TComp getElement(int pos) const;

	// adds an element in the sortedList (to the corresponding position)
	// DONE
    void add(TComp e);

	// removes an element from a given position
	// returns the removed element
	// throws an exception if the position is not valid
    // DONE
	TComp remove(int pos);

	// searches for an element and returns the first position where the element appears or -1 if the element is not in the list
	// DONE
    int search(TComp e) const;

	// returns an iterator set to the first element of the list or invalid if the list is empty
    // DONE
    ListIterator iterator();

	// destructor
    // DONE
	~SortedIndexedList();

};
