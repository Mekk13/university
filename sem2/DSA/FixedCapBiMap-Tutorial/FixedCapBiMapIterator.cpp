#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>
using namespace std;


FixedCapBiMapIterator::FixedCapBiMapIterator(const FixedCapBiMap& d) : map(d)
{
	this->currentPosition = 0;
}


void FixedCapBiMapIterator::first() {
	this->currentPosition = 0;
}


void FixedCapBiMapIterator::next() {
	if (this->currentPosition == this->map.mapsize)
		throw exception();
	this->currentPosition++;
}


TElem FixedCapBiMapIterator::getCurrent(){
	if (this->currentPosition == this->map.mapsize)
		throw exception();
	return this->map.elements[this->currentPosition];
}


bool FixedCapBiMapIterator::valid() const {
	return this->currentPosition < this->map.mapsize;
}


/// Complexity: AC=WC=TC= Theta(1)
void FixedCapBiMapIterator::previous()
{
	//throws an exception if the iterator is not valid:
	if (!valid())
		throw exception();

	if (this->currentPosition == 0) { //if we are on the first position

		this->currentPosition = this->map.mapsize; //makes the iterator invalid
		return;
	}

	this->currentPosition--;
}



