#include "ShortTest.h"
#include <assert.h>
#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <utility>
#include <iostream>


void testAll() { //call each function to see if it is implemented
	FixedCapBiMap m(10);
	assert(m.isEmpty() == true);
	assert(m.size() == 0); //add elements
	assert(m.add(5,5)==true);
	assert(m.add(1,111)==true);
	assert(m.add(10,110)==true);
	assert(m.add(7,7)==true);
	assert(m.add(1,1)==true); // this is the second value for key 1
	assert(m.add(1, 3) == false); // we cannot add a third value
	assert(m.add(10,10)==true);
	assert(m.add(-3,-3)==true);
	assert(m.size() == 7);
	std::pair<TValue, TValue> res = m.search(10);
	std::pair<TValue, TValue> ans1(110, 10);
	std::pair<TValue, TValue> ans2(10, 110);
	std::pair<TValue, TValue> ans3(NULL_TVALUE, NULL_TVALUE);
	assert(((res == ans1) || (res == ans2)));
	assert(m.search(16) == ans3);
	assert(m.remove(1,1) == true);
	assert(m.remove(6, 6) == false);
	assert(m.remove(5, 7) == false);
	assert(m.isEmpty() == false);
	assert(m.isFull() == false);
	assert(m.size() == 6);


	TElem e;
	FixedCapBiMapIterator id = m.iterator();
	id.first();
	int s1 = 0, s2 = 0;
	while (id.valid()) {
		e = id.getCurrent();
		s1 += e.first;
		s2 += e.second;
		id.next();
	}
	assert(s1 == 30);
	assert(s2 == 240);


	///test extra functionality:

	
	FixedCapBiMap m1(10);
	assert(m1.add(1, 5) == true);
	assert(m1.add(2, 6) == true);
	assert(m1.add(3, 7) == true);
	assert(m1.add(4, 8) == true);
	assert(m1.add(5, 9) == true);
	assert(m1.add(6, 10) == true);
	assert(m1.add(7, 11) == true);
	assert(m1.add(8, 12) == true);
	//we have elements 5,6,7,8,9,10,11,12 in m1 (with keys 1->8)

	TElem q;
	FixedCapBiMapIterator itr = m1.iterator();
	itr.first();
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= 7; i++) {
		itr.next();
	}
	///we are currently on the 8'th element (7'th index!) 
	while (itr.valid()) {
		q = itr.getCurrent();
		sum1 += q.first;
		sum2 += q.second;
		itr.previous();
	}

	assert(sum1 == 36);
	assert(sum2 == 68);

}


