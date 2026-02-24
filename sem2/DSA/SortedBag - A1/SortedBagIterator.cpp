#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;


/// BC=WC=TC= Theta(1);
SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->currentPosition = 0;
}


/// BC=WC=TC= Theta(1);
TComp SortedBagIterator::getCurrent() {
	if (this->currentPosition == this->bag.bagSize)
		throw exception();
	return this->bag.elements[this->currentPosition];
}


/// BC=WC=TC= Theta(1);
bool SortedBagIterator::valid() {
	return this->currentPosition < this->bag.bagSize;
}


/// BC=WC=TC= Theta(1);
void SortedBagIterator::next() {
	if (this->currentPosition == this->bag.bagSize)
		throw exception();
	this->currentPosition++;
}


/// BC=WC=TC= Theta(1);
void SortedBagIterator::first() {
	this->currentPosition = 0;
}

