#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

//BC=WC=TC=Theta(1)
ListIterator::ListIterator(const IndexedList& list, int current) : list(list), current(current) {}

//BC=WC=TC=Theta(1)
void ListIterator::first(){
    current = list.head;
}

//BC=WC=TC=Theta(1)
void ListIterator::next(){
    if (current == -1 )
        throw std::exception("Iterator can't go to the next element. Invalid position.");
    current = list.next[current];
}

//BC=WC=TC=Theta(1)
bool ListIterator::valid() const{
    return (current != -1);
}

//BC=WC=TC=Theta(1)
TElem ListIterator::getCurrent() const{
    if(valid())
	    return list.elements[current];
    throw std::exception("Invalid position.");
}