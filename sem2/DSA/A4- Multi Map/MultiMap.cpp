#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

// BC = WC = TC = Theta(1)
int MultiMap::hash(TKey key, int cap)
{
	return (key % cap +cap) % cap;
}

// BC Theta(sqrt(n+1)) WC=Theta(nlogn) TC= O(nlog n)
int MultiMap::nextPrime(int n) {
	int prime = n;
	bool found = false;

	while (!found) {
		prime++;
		found = true;
		for (int i = 2; i * i <= prime; i++) {
			if (prime % i == 0) {
				found = false;
				break;
			}
		}
	}

	return prime;  
}

// BC=WC=TC=Theta(n) , n->map size
void MultiMap::filter(Condition cond)
{
	int index = 0;
	int checked = 0;
	while (checked<=this->mapsize) {
		if (this->elements[index] != NULL_TELEM && this->elements[index] != DELETED_TELEM) {
			if (!cond(this->elements[index].first)) {
				this->elements[index] = DELETED_TELEM;
				this->mapsize--;
			}
			checked++;
		}
		index++;
	}
}


// BC = Theta ( n + sqrt(m)) WC= n*m log m TC= O(n*m log m )   where n- current nr of elements and m -> new capacity 
void MultiMap::resize()
{
	int new_capacity = nextPrime(this->capacity * 2);

	TElem* new_array = new TElem[new_capacity];

	for (int i = 0; i < new_capacity; i++) {
		new_array[i] = NULL_TELEM;
	}

	rehash(new_array, new_capacity);

	delete[] this->elements;

	this->capacity = new_capacity;
	this->elements = new_array;
}

// BC=WC=TC = Theta(n)
void MultiMap::rehash(TElem* new_elements, int new_capacity)
{
	for (int i = 0; i < this->capacity; i++) {
		if (elements[i] != NULL_TELEM && elements[i] != DELETED_TELEM) {
			TKey key = elements[i].first;
			TValue value = elements[i].second;

			int index = hash(key, new_capacity);
			int j = 1;

			while (new_elements[index] != NULL_TELEM) {
				index = hash(key + j * j, new_capacity);
				j++;
			}
			new_elements[index] = TElem(key, value);
		}
	}
}

// BC=WC=TC = Theta(c) , c -> initial capacity
MultiMap::MultiMap() {
	this->elements = new TElem[11];
	this->capacity = 11;
	this->mapsize = 0;
	for (int i = 0; i < capacity; ++i) {
		elements[i] = NULL_TELEM; 
	}
}

// BC=Theta(1) WC=Theta(n) TC=O(n)
void MultiMap::add(TKey c, TValue v) {
	if (this->mapsize >= this->capacity)
		resize();

	int index = hash(c,this->capacity);
	int j = 1;
	while (this->elements[index] != NULL_TELEM && this->elements[index] != DELETED_TELEM) {
		index = hash(c + j * j, this->capacity);
		j++;
	}
	this->elements[index] = TElem(c, v);
	this->mapsize++;
}


// BC=Theta(1) WC=Theta(n) TC=O(n)
bool MultiMap::remove(TKey c, TValue v) {
	int index = hash(c,this->capacity);
	int j = 1;
	while ((this->elements[index].first != c || this->elements[index].second != v) && this->elements[index] != NULL_TELEM) {
		index = hash(c + j * j, this->capacity);
		j++;
	}
	if (this->elements[index].second == v) {
		this->elements[index] = DELETED_TELEM;
		this->mapsize--;
		return true;
	}

	return  false;
}


// BC=Theta(1) WC=Theta(n) TC=O(n)
vector<TValue> MultiMap::search(TKey c) const {
	vector<TValue> values;
	int index = (c % this->capacity + this->capacity) % this->capacity;  
	int j = 1;
	while (this->elements[index] != NULL_TELEM) {
		if (this->elements[index] != DELETED_TELEM && this->elements[index].first == c) {
			values.push_back(this->elements[index].second);
		}
		int temp = c + j * j;
		index = (temp % this->capacity + this->capacity) % this->capacity;
		j++;
	}
	return values;
}

// BC=WC=TC=Theta(1)
int MultiMap::size() const {
	return this->mapsize;
}

// BC=WC=TC=Theta(1)
bool MultiMap::isEmpty() const {
	return this->mapsize == 0;
}

// BC=WC=TC=Theta(1)
MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}

// BC=WC=TC=Theta(1)
MultiMap::~MultiMap() {
	delete[] this->elements;
}

