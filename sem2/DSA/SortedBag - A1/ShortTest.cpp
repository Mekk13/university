#include "ShortTest.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <assert.h>
#include <iostream>

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

	///Test the extra functionality

	SortedBag s1(relation1);
	s1.add(5);
	s1.add(5);
	s1.add(5);
	s1.add(6);
	s1.add(0);
	s1.add(0);
	s1.add(5);
	s1.add(10);
	s1.add(10);
	s1.add(8);
	s1.add(8);
	s1.add(13);

	SortedBag s2(relation1);
	s2.add(5);
	s2.add(6);
	s2.add(0);
	s2.add(5);
	s2.add(10);
	s2.add(8);

	s1.Intersection(s2);
	assert(!s1.search(13));
	assert(s1.nrOccurrences(0) == 1);
	assert(s1.nrOccurrences(5) == 2);
	assert(s1.nrOccurrences(6) == 1);
	assert(s1.nrOccurrences(8) == 1);
	assert(s1.nrOccurrences(10) == 1);
}

