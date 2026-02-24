#include "SortedBag.h"
#include "SortedBagIterator.h"
#include<iostream>

///Theta(1)
SortedBag::SortedBag(Relation r) {
	
	this->capacity = 1;
	this->bagSize = 0;
	this->elements = new TElem[this->capacity]; //dynamic alloc <3
	this->relation = r;
}

///BC=Theta(log n) , WC = Theta(n) , TC= O(n)
void SortedBag::add(TComp e) {
	if (this->capacity == this->bagSize)
		resize();
	int left{ 0 }, right{ this->bagSize - 1 }, pos{ this->bagSize };
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (!this->relation(this->elements[mid], e))
		{
			pos = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	for (int j = this->bagSize - 1; j >= pos; j--) {
		this->elements[j + 1] = this->elements[j];
	}
	this->elements[pos] = e;
	this->bagSize++;
}


///BC=Theta(log n) , WC = Theta(n) , TC= O(n)
bool SortedBag::remove(TComp e) {

	int left{ 0 }, right{ this->bagSize -1 }, pos = -1;
	while (left <= right) {
		int mid = left+(right - left) / 2;
		if (this->elements[mid] == e) {
			pos = mid;
			break;
		}
		if (this->relation(this->elements[mid], e)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	if(pos==-1)
		return false;

	for (int j = pos; j < this->bagSize - 1; j++) {
		this->elements[j] = this->elements[j + 1];
	}
	this->bagSize--;
	return true;
}


//Binary search BC= Theta(1), WC=Theta(log n), TC=Theta(log n)
bool SortedBag::search(TComp elem) const {
	
	int l{ 0 }, r{ this->bagSize - 1 };
	while (l <= r) {
		int m = (l + r) / 2;
		if (this->elements[m] == elem)
			return true;
		if (this->relation(elements[m], elem)) {
			l = m + 1;
		}
		else
			r = m - 1;
	}
	return false;
}


//BC= Theta(log n), WC=Theta(log n), TC=Theta(log n)
int SortedBag::nrOccurrences(TComp elem) const {
	int left = 0, right = this->bagSize - 1, first = -1, last = -1;

	// Find the first occurrence
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (this->elements[mid] == elem) {
			first = mid;
			right = mid - 1; 
		}
		else if (this->relation(this->elements[mid], elem)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	if (first == -1)
		return 0;

	left = 0, right = this->bagSize - 1;

	// Find the last occurrence
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (this->elements[mid] == elem) {
			last = mid;
			left = mid + 1;  
		}
		else if (this->relation(this->elements[mid], elem)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return last - first + 1;
}


/// BC=WC=TC= Theta(1)
int SortedBag::size() const {
	return this->bagSize;
}


/// BC=WC=TC= Theta(1)
bool SortedBag::isEmpty() const {
	return this->bagSize == 0;
}


/// BC=WC=TC= Theta(1)
SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


/// BC=WC=TC= Theta(1)
SortedBag::~SortedBag() {
	delete[] this->elements;
}


/// BC=WC=TC = Theta(n+m) n->size of this, m -> size of given bag
void SortedBag::Intersection(SortedBag& b)
{
	int capacity = max(this->bagSize, b.bagSize);
	TElem* newElements = new TElem[capacity];
	int k{ 0 }, i{ 0 }, j{ 0 };
	while (i < this->bagSize && j < b.bagSize) {
		if (this->elements[i] == b.elements[j]) {
			int c_this = 0, c_that = 0;
			int temp_i{ i }, temp_j{ j };

			while (temp_i < this->bagSize && this->elements[temp_i] == this->elements[i]) {
				c_this++;
				temp_i++;
			}
			while (temp_j < b.bagSize && b.elements[temp_j] == this->elements[i]) {
				c_that++;
				temp_j++;
			}

			int mini;
			if (c_this < c_that)
				mini = c_this;
			else
				mini = c_that;

			for (int s = 0; s < mini; s++) {
				newElements[k] = this->elements[i];
				k++;
			}
			i += ( temp_i - i);
			j += (temp_j - j);
		}
		else {
			if (this->relation(this->elements[i], b.elements[j])) {
				i++;
			}
			else
				j++;
		}
	}
	delete[] this->elements;
	this->elements = newElements;
	this->bagSize = k;

}



/// BC=WC=TC= Theta(n)  , n=this->size *2
void SortedBag::resize()
{
	this->capacity *= 2;
	TElem* elems = new TElem[this->capacity];
	for (int i = 0; i < this->size(); i++) {
		elems[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = elems;
}