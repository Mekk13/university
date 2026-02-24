#pragma once
#include "repo.h"
#include "Product.h"
#include "Date.h"
#include "UndoRepo.h"


typedef struct {
	Repository* repo;
}Service;

Service* create_service(Repository* repo);
void destroy_service(Service* s);

int add_product(Service* s,char* name, char* category, int q, int day, int month, int year,int u);
int delete_product(Service* s, char* name, char* category,int u);
int update_product(Service* s, char* name, char* category, char* new_name, char* new_cat, int q, Date* d,int u);

Product** get_products_by_name_contains(Service* s, const char* str, int* num_found);
Product** get_prods_that_expire_by_cat(Service* s, const char* cat, int days, int* num_found);

void sort_products_bubble_desc(Service* s, Product** prods, int num);
void merge(Product** prods, int left, int mid, int right);
void mergeSort(Product** prods, int left, int right);
void sort_products_merge(Service* s, Product** prods, int num);

void get_current_date(int* day, int* month, int* year);

//undo redo:

void undo(Service* s);
void redo(Service* s);
void pushRedo(Operation op);
void pushUndo(Operation op);