#include "MultiMapIterator.h"
#include "MultiMap.h"

//BC = Theta(1) WC = Theta(n) TC = O(n)
MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	this->currentindex = 0;
	this->visitedelements = 0;
	first();
}

// BC=WC=TC=Theta(1)
TElem MultiMapIterator::getCurrent() const{
	if (!valid()) {
		throw std::exception("Iterator is not valid.");
	}
	return this->col.elements[this->currentindex];
}

// BC=WC=TC=Theta(1)
bool MultiMapIterator::valid() const {
	return currentindex < col.capacity && col.elements[currentindex] != NULL_TELEM && col.elements[currentindex] != DELETED_TELEM;
}

//BC = Theta(1) WC = Theta(n) TC = O(n)
void MultiMapIterator::next() {
	if (!valid()) {
		throw std::exception();
	}
	currentindex++;
	while (this->currentindex < this->col.capacity && (col.elements[currentindex] == NULL_TELEM || col.elements[currentindex] == DELETED_TELEM)) {
		this->currentindex++;
	}
	if (currentindex >= col.capacity) {
		currentindex = col.capacity;  // Out of bounds (invalid)
	}
	if (valid()) {
		visitedelements++;
	}
}

//BC = Theta(1) WC = Theta(n) TC = O(n)
void MultiMapIterator::first() {
	this->currentindex = 0;
	this->visitedelements = 0;
	while (this->currentindex < this->col.capacity && (col.elements[currentindex]==NULL_TELEM || col.elements[currentindex] == DELETED_TELEM)) {
		this->currentindex++;
	}
	if (currentindex < col.capacity && col.elements[currentindex] != NULL_TELEM) {
		visitedelements = 1;
	}
	else {
		currentindex = col.capacity;
	}
}

