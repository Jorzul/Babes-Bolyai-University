#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);
	int current; //the position of the current element

public:
	TComp getCurrent();
	bool valid() const;
	void next();
	void first();
};

