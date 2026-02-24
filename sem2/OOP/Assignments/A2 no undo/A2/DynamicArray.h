#pragma once

typedef void* TElem;
typedef void (*DestructorFunction)(TElem); //pointer to a function

typedef struct {
	TElem* elems;
	int size, capacity;
	DestructorFunction destroy;

}DynamicArray;



DynamicArray* createDynamicArray(int capacity, DestructorFunction destroyF);
void destroyArray(DynamicArray* arr);
void addElem(DynamicArray* arr, TElem elem);
int deleteElem(DynamicArray* arr, int index);
void resize(DynamicArray* arr);
int getSize(DynamicArray* arr);

void* getElement(DynamicArray* arr, int index);