#include <assert.h>
#include <cstdio>
#include <exception>

#include "ListIterator.h"
#include "SortedIndexedList.h"

using namespace std;

bool relation1(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedIndexedList list = SortedIndexedList(relation1);
    /*SortedIndexedList list2 = SortedIndexedList(relation1);

    list2.add(1);
    list2.add(2);
    list2.add(3);
    list2.add(4);
    list2.add(5);

    ListIterator iterator2 = list2.iterator();

    iterator2.first();
    assert(iterator2.getCurrent() == 5);
    iterator2.jumpForward(3);

    assert(iterator2.valid());
    try {
        iterator2.jumpForward(10);
    } catch (exception&) {
        assert(true);
    }*/

	assert(list.size() == 0);
	assert(list.isEmpty());
    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
    ListIterator iterator = list.iterator();
    assert(iterator.valid());
    iterator.first();
    assert(iterator.getCurrent() == 1);
    iterator.next();
    assert(!iterator.valid());
    iterator.first();
    assert(iterator.valid());
    assert(list.search(1) == 0);
    assert(list.remove(0) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());
}

