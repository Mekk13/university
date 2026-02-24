#include "DynamicArray.h"
#include <stdlib.h>
#include <stdio.h>

DynamicArray* createDynamicArray(int capacity, DestructorFunction destroyF)
{
	DynamicArray* arr = malloc(sizeof(DynamicArray));
	if (arr == NULL) {
		return NULL;
	}
	arr->size = 0;
	arr->capacity = capacity;
	arr->destroy = destroyF;
	arr->elems = malloc(arr->capacity * sizeof(TElem));
	if (arr->elems == NULL) {
		free(arr);
		return NULL;
	}
	return arr;
}

void* getElement(DynamicArray* arr, int index) {
	if (index < 0 || index >= arr->size) {
		// Handle invalid index here, e.g., return NULL or throw an error
		return NULL;
	}
	return arr->elems[index];
}


void destroyArray(DynamicArray* arr)
{
	if (arr == NULL)
		return;
	for (int i = 0; i < arr->size; i++) {
		arr->destroy(arr->elems[i]);
	}
	free(arr->elems);
	arr->elems = NULL; //avoids a pointer to invalid memory! 
	free(arr);
}

void addElem(DynamicArray* arr, TElem elem)
{
	if (arr == NULL || arr->elems == NULL)
		return;
	if (arr->size == arr->capacity) {
		resize(arr);
	}
	arr->elems[arr->size++] = elem; //TElem is a POINTER and the array is also an array of pointers
}

int deleteElem(DynamicArray* arr, int index)
{
	if (arr == NULL || arr->elems == NULL) {
		return -1;
	}
	int found = 0;
	for (int i = 0; i < arr->size; i++) {
		if (i==index) {
			//if the address at elems[i]==address of the element , because we work with pointers <3
			found = 1;
			arr->destroy(arr->elems[i]);
			for (int j = i; j < arr->size - 1; j++) {
				arr->elems[j] = arr->elems[j + 1];
			}
			arr->size--;
		}
	}
	if (arr->size < arr->capacity / 4) {
		resize(arr);  // Resize to a smaller capacity if necessary 
	}

	if (!found)
		return -1;
	return 1;
		
}

void resize(DynamicArray* arr)
{
	if (arr == NULL || arr->elems == NULL) {
		return;
	}
	arr->capacity *= 2;
	TElem* aux = realloc(arr->elems, arr->capacity * sizeof(TElem));

	if (aux == NULL) {
		return;
	}

	arr->elems = aux;
}

int getSize(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;
	return arr->size;
}
