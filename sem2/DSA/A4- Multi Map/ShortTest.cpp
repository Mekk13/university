#include "ShortTest.h"
#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <assert.h>
#include <vector>
#include<iostream>

bool condition(TKey c) {
	if (c % 2 == 1)
		return true;
	return false;
}

void testAll() {
	MultiMap m;
	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(1, 500);
	m.add(2, 600);
	m.add(4, 800);

	assert(m.size() == 6);

	assert(m.remove(5, 600) == false);
	assert(m.remove(1, 500) == true);

	assert(m.size() == 5);

    vector<TValue> v;
	v=m.search(6);
	assert(v.size()==0);

	v=m.search(1);
	assert(v.size()==1);

	assert(m.isEmpty() == false);

	MultiMapIterator im = m.iterator();
	assert(im.valid() == true);
	while (im.valid()) {
		im.getCurrent();
		im.next();
	}
	assert(im.valid() == false);
	im.first();
	assert(im.valid() == true);
	//extra test:
	
	MultiMap a;
	a.add(1, 1);
	a.add(2, 2);
	a.add(3, 3);
	a.add(4, 2);
	a.add(5, 4);
	a.add(3, 5);

	a.filter(condition);
	vector<TValue> vec;
	vec = a.search(2);
	assert(vec.size() == 0);
	vec = a.search(4);
	assert(vec.size() == 0);
	vec = a.search(5);
	assert(vec.size() == 1);

	vec = a.search(1);
	assert(vec.size() == 1);
	vec = a.search(3);
	assert(vec.size() == 2);
}
