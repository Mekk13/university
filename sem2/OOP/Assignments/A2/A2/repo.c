#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "repo.h"
#include "DynamicArray.h"
#include "Product.h"

#define INITIAL_CAPACITY 50 //default capacity for the repo 

Repository* create_repo()
{ 
	Repository* repo = (Repository*)malloc(sizeof(Repository)); //hold space for the repo :))

	if (repo == NULL) {
		return NULL;
	}
	
	repo->products = createDynamicArray(1, &destroyProduct);

	if (repo->products == NULL) {
		free(repo);
		return NULL;
	}

	return repo;
}

void r_add_product(Repository* repo, Product* product)
{
	for (int i = 0; i < repo->products->size; i++) {
		if(strcmp(getName(repo->products->elems[i]),getName(product))==0 && strcmp(getCategory(repo->products->elems[i]),getCategory(product))==0) {
			int new_quantity = getQuantity(repo->products->elems[i]) + getQuantity(product);
			setQuantity(repo->products->elems[i], new_quantity);
			destroyProduct(product);
			return;
		}
	}
	
	if (repo->products->size >= repo->products->capacity) {
		resize(repo->products);
	}

	addElem(repo->products, product);
}

int r_delete_product(Repository* repo, Product* product, Product p)
{
	for (int i = 0; i < repo->products->size; i++) {
		if (strcmp(getName(repo->products->elems[i]), getName(product)) == 0 && strcmp(getCategory(repo->products->elems[i]), getCategory(product)) == 0) {
			int new_quantity = getQuantity(repo->products->elems[i]);
			if (new_quantity - 1 != 0) {
				setQuantity(repo->products->elems[i], new_quantity - 1);
				return 0;
			}
			else
			{
				deleteElem(repo->products, i);
				return 0;
			}
		}
	}
	return -1;
}

int r_update_product(Repository* repo, Product* p, Product product)
{
	if (p == NULL)
		return -1;
	setName(p, getName(&product));
	setCategory(p, getCategory(&product));
	setQuantity(p, getQuantity(&product));
	setExpDate(p, getExpDate(&product));
	return 0;
}

Product** r_get_all_products(Repository* repo, int* number)
{
	*number = repo->products->size;
	return (Product**)repo->products->elems; 
}

Product* r_get_product_by_name_and_cat(Repository* repo, const char* name, const char* category)
{
	for (int i = 0; i < repo->products->size; i++) {
		if (strcmp(getName(repo->products->elems[i]), name) == 0 && strcmp(getCategory(repo->products->elems[i]), category) == 0) {
			return repo->products->elems[i];
		}
	}
	return NULL; ///error! 
}

int r_get_size(Repository* repo)
{
	return getSize(repo->products);
}

void destroy_repo(Repository* repo)
{
	if (repo == NULL)
		return;
	destroyArray(repo->products);
	free(repo);
}


