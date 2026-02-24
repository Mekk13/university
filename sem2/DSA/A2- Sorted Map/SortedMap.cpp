#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

//BC=Theta(1) WC =Theta(n), T = O(n)
void SortedMap::replace(TKey k, TValue oldValue, TValue newValue)
{
	Node* current = this->head->next;
	while (current != this->tail && this->r(current->elem.first, k)) {
		if (current->elem.first == k) {
			if (current->elem.second == oldValue)
				current->elem.second = newValue;
			return;
		}
		current = current->next;
	}
}

//BC=WC=AC = Theta(1)
SortedMap::SortedMap(Relation r) {
	this->r = r;
	this->head = new Node;
	this->tail = new Node;
	this->head->next = this->tail;
	this->tail->prev = this->head;
	this->length = 0;
}

// bc = Theta(1) , wc= Theta(n) , T = O(n)
TValue SortedMap::add(TKey k, TValue v) {
	Node* current = this->head->next;

	Node* new_node = new Node;
	new_node->elem.first = k;
	new_node->elem.second = v;

	if (current == this->tail) {
		new_node->next = this->head->next;
		new_node->prev = this->head;
		this->head->next = new_node;
		this->tail->prev = new_node;
		this->length++;
		return NULL_TVALUE;
	}

	while (current != this->tail && this->r(current->elem.first, k)) {
		if (current->elem.first == k) {
			int old_value = current->elem.second;
			current->elem.second = v;
			return old_value;
		}
		current = current->next;
	}
	
	int old_value1 = current->elem.second;
	new_node->next = current;
	new_node->prev = current->prev;
	current->prev->next = new_node;
	current->prev = new_node;
	this->length++;
	return NULL_TVALUE;
}

/// bc = Theta(1) , wc= Theta(n), ac = O(n)
TValue SortedMap::search(TKey k) const {
	Node* current = this->head->next;
	while (current != this->tail && this->r(current->elem.first, k)) {
		if (current->elem.first == k) {
			return current->elem.second;
		}
		current = current->next;
	}
	return NULL_TVALUE;
}

//bc = Theta(1) , wc= Theta(n), ac = O(n)
TValue SortedMap::remove(TKey k) {
	
	Node* current = this->head->next;


	while (current != this->tail && this->r(current->elem.first, k)) {
		if (current->elem.first == k) {
			int value = current->elem.second;
			Node* aux = current->prev;
			aux->next = current->next;
			if (current->next != nullptr)
				current->next->prev = aux;
			else
				this->tail->prev = aux;
			delete current;
			this->length--;
			return value;
		}
		current = current->next;
	}
	return NULL_TVALUE;
}

//AC=WC=BC=Theta(1)
int SortedMap::size() const {
	return this->length;
}


//AC=WC=BC=Theta(1)
bool SortedMap::isEmpty() const {
	if (this->length == 0)
		return true;
	return false;
}


//AC=WC=BC=Theta(1)
SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}


//AC=WC=BC=Theta(1)
SortedMap::~SortedMap() {
	Node* current = this->head->next;
	while (current != this->tail) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	delete this->head;
	delete this->tail;
}
