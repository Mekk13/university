#pragma once
#include "Product.h"
#include "DynamicArray.h"

typedef struct {
	DynamicArray* products; ///pointer bc dynamic array
}Repository;

Repository* create_repo();
void r_add_product(Repository* repo, Product* product);
int r_delete_product(Repository* repo, Product* product, Product p);
int r_update_product(Repository* repo,Product* p, Product product);
Product** r_get_all_products(Repository* repo, int* number);
Product* r_get_product_by_name_and_cat(Repository* repo, const char* name, const char* category);

int r_get_size(Repository* repo);
void destroy_repo(Repository* repo);

