#pragma once

template <typename T>
class DynamicVector {
private:
	T* elems;
	int size, capacity;
	void resize();

public:
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector& vector);
	~DynamicVector();

	DynamicVector& operator=(const DynamicVector& v);
	T& operator[](int pos);

	void add(T e);
	void remove_element(int index);
	void update_element(int index_of_elem_to_update, T updatedElem);
	int getSize() const;

	T getElement(int indexOfElementToGet);
	int findPositionOfElement(T elementToFindPosition);

};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& vector) {
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++) {
		this->elems[i] = vector.elems[i];
	}
}

template <typename T>
DynamicVector<T>::~DynamicVector() {
	delete[] this->elems;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	T* aux = new T[this->capacity];
	delete[] this->elems;
	this->elems = aux;

	for (int i = 0; i < this->size; i++) {
		this->elems[i] = v.elems[i];
	}

	return *this;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
void DynamicVector<T>::add(T e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template<typename T>
inline void DynamicVector<T>::remove_element(int index)
{
	if (index < 0 || index >= this->size)
		return;
	T* temp = new T[this->capacity];
	for (int i = 0; i < index; i++) {
		temp[i] = this->elems[i];
	}
	for (int i = index + 1; i < this->size; i++) {
		temp[i - 1] = this->elems[i];
	}
	delete[] this->elems;
	this->elems = temp;
	this->size--;

	if (this->size < this->capacity / 4) {
		this->resize();  // Shrink the array
	}
}

template<typename T>
inline void DynamicVector<T>::update_element(int index_of_elem_to_update, T updatedElem)
{
	if (index_of_elem_to_update < 0 || index_of_elem_to_update >= this->size)
		return;
	this->elems[index_of_elem_to_update] = updatedElem;
}



template <typename T>
void DynamicVector<T>::resize()
{
	this->capacity *= 2;

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline T DynamicVector<T>::getElement(int indexOfElementToGet)
{
	return this->elems[indexOfElementToGet];
}

template<typename T>
inline int DynamicVector<T>::findPositionOfElement(T elementToFindPosition)
{
	for (int index = 0; index < this->size; index++)
		if (elementToFindPosition == this->elems[index])
			return index;
	return -1;
}

