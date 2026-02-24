#include <exception>
#include <iostream>
#include "IndexedList.h"
#include "ListIterator.h"

// BC=Theta(n) WC=Theta(n) TC=Theta(n)
void IndexedList::resize()
{
    int newcap=cap*2;
    TElem* new_elems = new TElem[newcap];
    int* new_next = new int[newcap];
    for (int i = 0; i < cap; i++) {
        new_elems[i] = elements[i];
        new_next[i] = next[i];
    }
    for (int i = cap; i < newcap; i++) {
        new_next[i] = i + 1;
    }
    new_next[newcap - 1] = -1;
    if (firstEmpty == -1)
        firstEmpty = cap;
    delete[] elements;
    delete[] next;

    elements = new_elems;
    next = new_next;
    cap = newcap;
}

// BC=WC=TC=Theta(1)
IndexedList::IndexedList(): cap(10),head(-1),tail(-1),firstEmpty(1),_size(0) {
    elements = new TElem[cap];
    next = new int[cap];
    for (int i = 0; i < cap; i++) {
        next[i] = i + 1;
    }
    next[cap - 1] = -1;
}

//BC=WC=TC=Theta(1)
int IndexedList::size() const {
    return _size;
}

//BC=WC=TC=Theta(1)
bool IndexedList::isEmpty() const {
    if (_size == 0)
        return true;
    return false;
}

// BC = Theta(1) WC = Theta(n) TC=O(n)
TElem IndexedList::getElement(int pos) const {
    if (pos < 0 ) {
        throw std::exception("invalid position");
    }
    int nod = head;
    int poscrr = 0;
    while (nod != -1 && poscrr<pos) {
        poscrr++;
        nod = next[nod];
    }
    if (nod != -1)
        return elements[nod];
    else
        throw std::exception("invalid position");
}

// BC = Theta(1) WC = Theta(n) TC=O(n)
TElem IndexedList::setElement(int pos, TElem e) {
    if ( pos < 0)
        throw std::exception("invalid position");
    int nod = head;
    int poscrr = 0;
    while (nod != -1 && poscrr < pos) {
        poscrr++;
        nod = next[nod];
    }
    if (nod != -1) {
        TElem old = elements[nod];
        elements[nod] = e;
        return old;
    }
    else
        throw std::exception("invalid position");
}

//BC=WC=AC=Theta(1)
void IndexedList::addToEnd(TElem e) {
    if (_size == cap || firstEmpty==-1)
        resize();
    int position = firstEmpty;
    firstEmpty = next[firstEmpty];
    elements[position] = e;
    next[position] = -1;
    if (head == -1) {
        head = position;
        tail = position;
    }
    else {
        next[tail] = position;
        tail = position;
    }
    _size++;
}

// BC= WC = TC = Theta(1)
void IndexedList::inserFirst(TElem e)
{
    if (firstEmpty == -1)
        resize();
    int pos = firstEmpty;
    elements[pos] = e;
    firstEmpty = next[firstEmpty];
    next[pos] = head;
    head = pos;
    _size++;
}

//BC=Theta(1) WC=Theta(n) TC=O(n)
int IndexedList::removeFromKtoK(int k)
{
    if (k <= 0)
        throw std::exception("Invalid k!\n");
    if (_size < k)
        return 0;
    int count = 0;
    int nod = head;
    int pos = 1, crrpos = 0;
    int previous = -1;
    while (nod != -1) {
        if (pos == k) {
            int toDelete = nod;
            if (previous == -1) {
                head = next[nod];
            }
            else {
                next[previous] = next[nod];
            }
            if (nod == tail) {
                tail = previous;
            }
            nod = next[nod];
            next[toDelete] = firstEmpty;
            firstEmpty = toDelete;
            _size--;

            pos = 1;
            count++;
        }
        else {
            pos++;
            nod = next[nod];
            crrpos++; //there is a logical shift in the node position, even if they stay in the same place <3
        }
    }
    return count;
}


// TC = O(n) BC = Theta(1) , WC =Theta(n)
void IndexedList::addToPosition(int pos, TElem e) {
    if (pos < 0 )
        throw std::exception("invalid position");
    if (firstEmpty == -1)
        resize();
    if (pos == 0) {
        inserFirst(e);
    }
    else {
        int poscrr = 0;
        int nodcrr = head;
        while (nodcrr != -1 && poscrr < pos - 1) {
            poscrr++;
            nodcrr = next[nodcrr];
        }
        if (nodcrr != -1) {
            int newElem = firstEmpty;
            firstEmpty = next[firstEmpty];
            elements[newElem] = e;
            next[newElem] = next[nodcrr];
            next[nodcrr] = newElem;
            _size++;
        }
        else {
            throw std::exception("invalid position");
        }
    }
}

//BC=Theta(1) WC=Theta(n) TC=O(n)
TElem IndexedList::remove(int pos) {
    if (pos < 0)
        throw std::exception("invalid position");
    int current = head;
    int previous = -1;
    int crrpos = 0;
    while (current != -1 && crrpos < pos) {
        previous = current;
        current = next[current];
        crrpos++;
    }
    if(current==-1)
        throw std::exception("invalid position"); 

    TElem old = elements[current];

    if (current == head) {
        head = next[head];
    }
    else{
        next[previous] = next[current];
    }
    if (current == tail) {
        tail = previous;
    }
    next[current] = firstEmpty;
    firstEmpty = current;
    _size--;
    return old;
}

//BC=Theta(1) WC=Theta(n) TC=Theta(n)
int IndexedList::search(TElem e) const{
    int nod = head;
    int pos = 0;
    while (nod != -1) {
        if (elements[nod] == e)
            return pos;
        pos++;
        nod = next[nod];
    }
	return -1;
}

//BC=WC=TC=Theta(1)
ListIterator IndexedList::iterator() const {
    if(_size>0)
        return ListIterator(*this,head);   
    return ListIterator(*this, -1);
}

//BC=WC=TC=Theta(1)
IndexedList::~IndexedList() {
    delete[] elements;
    delete[] next;
}