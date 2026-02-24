#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

// BC = WC = AC = Theta(1)
SMIterator::SMIterator(const SortedMap& m) : map(m){
	this->current = this->map.head->next;
}

// BC = WC = AC = Theta(1)
void SMIterator::first() {
	this->current = this->map.head->next;
}

// BC = WC = AC = Theta(1)
void SMIterator::next(){
	if(!this->valid() )
		throw std::exception();
	this->current = this->current->next;
}

// BC = WC = AC = Theta(1)
bool SMIterator::valid() const {
	return (this->current != nullptr && this->current != map.tail);
}

// BC = WC = AC = Theta(1)
TElem SMIterator::getCurrent() const{
	if (!this->valid())
		throw std::exception();
	return this->current->elem;
}


