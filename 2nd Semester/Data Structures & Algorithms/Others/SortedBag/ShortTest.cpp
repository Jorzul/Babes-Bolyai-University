#include "ShortTest.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <cassert>

bool relation1(TComp e1, TComp e2) {
	return e1 <= e2;
}

void testAll() {
	SortedBag sb(relation1);
	sb.add(5);
	sb.add(6);
	sb.add(0);
	sb.add(5);
	sb.add(10);
	sb.add(8);

    SortedBag b(relation1);
    b.add(9);
    b.add(3);
    b.add(7);
    b.add(11);

    SortedBag c(relation1);
    c.add(99);
    c.add(55);

    assert(b.size() == 4);
    assert(c.size() == 2);

    b.addAll(c);
    assert(b.size() == 6);
    assert(sb.size() == 6);

    sb.addAll(b);

    assert(b.size() == 6);
    assert(sb.size() == 12);

    sb.remove(9);
    sb.remove(3);
    sb.remove(7);
    sb.remove(11);
    sb.remove(55);
    sb.remove(99);

	assert(sb.size() == 6);
	assert(sb.nrOccurrences(5) == 2);

	assert(sb.remove(5) == true);
	assert(sb.size() == 5);

	assert(sb.search(6) == true);
	assert(sb.isEmpty() == false);

	SortedBagIterator it = sb.iterator();
	assert(it.valid() == true);
	while (it.valid()) {
		it.getCurrent();
		it.next();
	}
	assert(it.valid() == false);
	it.first();
	assert(it.valid() == true);

}

