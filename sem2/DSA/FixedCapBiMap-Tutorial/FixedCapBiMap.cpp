#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"

FixedCapBiMap::FixedCapBiMap(int capacity) {
	if (capacity <= 0) {
		throw exception();
	}
	this->capacity = capacity;
	this->mapsize = 0;
	this->elements = new TElem[this->capacity]; //dynamic alloc
}

FixedCapBiMap::~FixedCapBiMap() {
	delete[] this->elements;
}

bool FixedCapBiMap::add(TKey c, TValue v){
	if (this->capacity == this->mapsize) {
		throw exception();
	}
	int count = 0;
	int index = 0;
	while (count < 2 && index < this->mapsize) {
		if (this->elements[index].first == c) {
			count++;
		}
		index++;
	}
	if (count >= 2) {
		return false;
	}

	this->elements[this->mapsize].first = c;
	this->elements[this->mapsize].second = v;
	this->mapsize++;
	return true;
}

ValuePair FixedCapBiMap::search(TKey c) const{
	ValuePair result;
	result.first = NULL_TVALUE;
	result.second = NULL_TVALUE;
	int nrfound = 0;
	int index=0;
	while (nrfound < 2 && index < this->mapsize) {
		if (this->elements[index].first == c) {
			if (nrfound == 0) {
				result.first = this->elements[index].second;
				nrfound++;
			}
			else {
				result.second = this->elements[index].second;
				nrfound++;
			}
		}
		index++;
	}

	return result;
}

bool FixedCapBiMap::remove(TKey c, TValue v){
	int index = 0;
	while (index < this->mapsize) {
		if (this->elements[index].first == c && this->elements[index].second == v){
			this->elements[index] = this->elements[this->mapsize - 1];
			this->mapsize--;
			return true;
		}
		index++;
	}
	return false;
}


int FixedCapBiMap::size() const {
	return this->mapsize;
}

bool FixedCapBiMap::isEmpty() const{
	return this->mapsize == 0;
}

bool FixedCapBiMap::isFull() const {
	return this->mapsize == this->capacity;
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}



