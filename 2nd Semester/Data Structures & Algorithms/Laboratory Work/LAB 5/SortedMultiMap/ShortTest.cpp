#include <assert.h>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);

    SortedMultiMap mine_smm1 = SortedMultiMap(relation1);
    SortedMultiMap mine_smm2 = SortedMultiMap(relation1);

    mine_smm1.add(1, 3);
    mine_smm1.add(3, 5);
    mine_smm1.add(6, 10);
    mine_smm1.add(4, 2);
    assert(mine_smm1.size() == 4);

    mine_smm2.add(1, 3);
    mine_smm2.add(3, 5);
    mine_smm2.add(6, 10);
    mine_smm2.add(4, 2);
    assert(mine_smm2.size() == 4);

    assert(mine_smm1.addIfNotPresent(mine_smm2) == 0);

    mine_smm1.remove(6, 10);
    assert(mine_smm1.size() == 3);

    assert(mine_smm1.addIfNotPresent(mine_smm2) == 1);

    mine_smm1.remove(4, 2);
    mine_smm2.add(11, 4);

    assert(mine_smm1.addIfNotPresent(mine_smm2) == 2);

    mine_smm2.add(3, 5);

    assert(mine_smm1.addIfNotPresent(mine_smm2) == 0);

	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(5,3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==1);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(5, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());
}

