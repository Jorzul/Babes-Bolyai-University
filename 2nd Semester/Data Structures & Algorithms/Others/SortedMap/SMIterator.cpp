#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	this->current = 0;
}
//Time Complexity: Theta(1)

void SMIterator::first(){
	this->current = 0;
}
//Time Complexity: Theta(1)

void SMIterator::next(){
    if (this->current >= this->map.map_size) {
        throw exception();
    }
    else {
        this->current++;
    }
}
//Time Complexity: Theta(1)

bool SMIterator::valid() const{
    if (this->current < this->map.map_size)
    {
        return true;
    }
    else {
        return false;
    }
}
//Time Complexity: Theta(1)

TElem SMIterator::getCurrent() const{
    if (!valid()) {
        throw exception();
    }
    TElem e = reinterpret_cast<const pair<int, int> &>(this->map.head[current]);
    return e;
}
//Time Complexity: Theta(1)


