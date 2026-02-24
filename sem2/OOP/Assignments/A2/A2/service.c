#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "service.h"
#include "Date.h"
#include "Product.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

Service* create_service(Repository* repo)
{
	Service* serv = malloc(sizeof(Service*));
	if (serv == NULL)
		return NULL;
	serv->repo = repo;
	return serv;
}

void destroy_service(Service* s)
{
	if (s == NULL)
		return;
	destroy_repo(s->repo);
	free(s);
}


int add_product(Service* s, char* name, char* category, int q, int day, int month, int year,int u)
{
	Date* d = createDate(day, month, year);

	if (name == NULL || category == NULL || q <= 0)
	{
		return -1;
	}
	if (!valid_date(d))
	{
		return -1;
	}
	Product* p = createProduct(name, category, q,d);
	r_add_product(s->repo, p);


	Operation op;
	op.type = ADD_PRODUCT;
	strcpy(op.name, name);
	strcpy(op.cat, category);
	op.quantity = q;
	op.day = day;
	op.month = month;
	op.year = year;
	if(u)
		pushUndo(op);

	free(d);
	return 0;
}

int delete_product(Service* s, char* name, char* category,int u)
{
	Product* p = r_get_product_by_name_and_cat(s->repo, name, category);
	if (p == NULL) {
		return -1;
	}

	Operation op;
	op.type = DELETE_PRODUCT;
	Product* p1 = r_get_product_by_name_and_cat(s->repo, name, category);
	strcpy(op.name, name);
	strcpy(op.cat, category);
	Date* d = getExpDate(p1);
	op.day = getDay(d);
	op.month = getMonth(d);
	op.year = getYear(d);
	op.quantity = getQuantity(p1);
	if(u)
		pushUndo(op);

	r_delete_product(s->repo, p,*p);
	return 0;
}

int update_product(Service* s, char* name, char* category,char* new_name,char* new_cat, int q, Date* d,int u)
{
	Operation op;
	op.type = UPDATE_PRODUCT;
	Product* pp = r_get_product_by_name_and_cat(s->repo,name, category);
	strcpy(op.prev_name, name);
	strcpy(op.prev_category, category);
	op.prev_quantity = getQuantity(pp);
	Date* temp_d = getExpDate(pp);
	op.prev_day = getDay(temp_d);
	op.prev_month = getMonth(temp_d);
	op.prev_year = getYear(temp_d);

	Product* p = r_get_product_by_name_and_cat(s->repo, name, category);
	if (p == NULL) {
		return -1;
	}
	Product* new_p = createProduct(new_name, new_cat, q, d);

	strcpy(op.name, new_name);
	strcpy(op.cat, new_cat);
	op.quantity = q;
	op.prev_day = getDay(d);
	op.prev_month = getMonth(d);
	op.prev_year = getYear(d);
	if(u)
		pushUndo(op);

	r_update_product(s->repo,p, *new_p);
	destroyProduct(new_p);
	return 0;
}

void get_current_date(int* day, int* month, int* year) {
	time_t t = time(NULL);
	struct tm* tm_info = localtime(&t);

	*day = tm_info->tm_mday;
	*month = tm_info->tm_mon+1;
	*year = tm_info->tm_year + 1900; //since 1900 so we add 1900

}

static int days_from_2000_to_date(int d, int m, int y) {
	//Function that calculates the number of days between year 2000 and a given date
	//Returns: the calculated number of days

	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int total_days = 0;
	for (int i = 2000; i < y; i++) {
		if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
			//leap year 
			total_days += 366; 
		}
		else {
			total_days += 365;
		}
	}
	for (int i = 0; i < m - 1; i++) {
		total_days += days_in_month[i];
	}
	total_days += d;
	return total_days;
}

Product** get_prods_that_expire_by_cat(Service* s, const char* cat, int days, int* num_found) {
	int nre,k=0;
	Product** p = r_get_all_products(s->repo, &nre);
	if (p == NULL || nre == 0) {
		return NULL;
	}
	if (cat[0] == '\0') {
		*num_found = r_get_size(s->repo);
		return p;
	}
	Product** prods = (Product**)malloc(sizeof(Product*) * nre);
	if (prods == NULL)
		return NULL;

	int d, m, y;
	get_current_date(&d, &m, &y);
	int d1 = days_from_2000_to_date(d, m, y);

	for (int i = 0; i < nre; i++) {
		Date* crrd = getExpDate(p[i]);
		int d2 = days_from_2000_to_date(getDay(crrd), getMonth(crrd), getYear(crrd));
		if (strcmp(getCategory(p[i]), cat) == 0 && (d2-d1 <= days)) {
			prods[k] = p[i];
			k++;
		}
	}
	*num_found = k;
	if (k == 0) {
		free(prods);
		return NULL;
	}
	return prods;
}

Product** get_products_by_name_contains(Service* s, const char* str, int* num_found)
{
	int number, k=0;
	Product** p;
	p = r_get_all_products(s->repo, &number);
	if (p == NULL || number == 0) {
		return NULL;
	}
	if (str[0]=='\0') {
		*num_found = r_get_size(s->repo);
		return p;
	}
	Product** prods;///here's an array where we will put the found product
	prods = (Product**)malloc(number*sizeof(Product*)); ///we will allocate the nr of products since that's the maximum anyway
	if (prods == NULL) {
		return NULL;
	}

	for (int i = 0; i < number; i++) {
		if (p[i] == NULL || p[i]->name==NULL) {
			return NULL;
		}
		if (strstr(getName((p[i])), str) != NULL) {
			prods[k] = p[i];
			k++;
		}
	}
	*num_found = k;
	if (k == 0) {
		free(prods);
		return NULL;
	}

	return prods;
}

void sort_products_bubble_desc(Service* s, Product** prods, int num) {
	///bubble sort
	int k = num;
	for (int i = 0; i < k - 1; i++) {
		int swapped = 0;
		for (int j = 0; j < k - i - 1; j++) {
			if (strcmp(getName(prods[j]), getName(prods[j + 1])) < 0) {
				Product* s;
				s = prods[j];
				prods[j] = prods[j + 1];
				prods[j + 1] = s;
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}

}

void merge(Product** prods, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	Product** leftArr = (Product**)malloc(sizeof(Product*) * n1);
	Product** rightArr = (Product**)malloc(sizeof(Product*) * n2);

	if (!leftArr || !rightArr) {
		return;
	}

	for (int i = 0; i < n1; i++) {
		leftArr[i] = prods[left + i];
	}
	for (int i = 0; i < n2; i++) {
		rightArr[i] = prods[mid+1 + i];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (getQuantity(leftArr[i]) >= getQuantity(rightArr[j])) {
			prods[k++] = leftArr[i++];
		}
		else {
			prods[k++] = rightArr[j++];
		}
	}

	while (i < n1) {
		prods[k++] = leftArr[i++];
	}
	while (j < n2) {
		prods[k++] = rightArr[j++];
	}

	free(leftArr);
	free(rightArr);
}

void mergeSort(Product** prods, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(prods, left, mid);
		mergeSort(prods, mid + 1, right);
		merge(prods, left, mid, right);
	}
}

void sort_products_merge(Service* s, Product** prods, int num) {
	mergeSort(prods, 0, num - 1);
}

//undo redo:

void undo(Service* s) {
	if (undoTop == -1) {
		printf("No operations to undo.\n");
		return;
	}

	// Pop the last operation from the undo stack
	Operation op = undoStack[undoTop--];

	// Perform undo based on the operation type
	switch (op.type) {
	case ADD_PRODUCT:
		// To undo an add, we delete the prod
		delete_product(s, op.name, op.cat,0);
		break;
	case DELETE_PRODUCT:
		// To undo a delete, we re-add the prod
		add_product(s, op.name, op.cat, 1, op.day, op.month, op.year,0);
		break;
	case UPDATE_PRODUCT: {
		// To undo an update, we revert to the previous prod
		Date* d = createDate(op.prev_day, op.prev_month, op.prev_year);
		update_product(s, op.name, op.cat, op.prev_name, op.prev_category, op.prev_quantity, d,0);
		free(d);
		break;
	}
	}
	// Push the operation to the redo stack
	pushRedo(op);
}

void redo(Service* s) {
	if (redoTop == -1) {
		printf("No operations to redo.\n");
		return;
	}
	Operation op = redoStack[redoTop--];

	switch (op.type) {
	case ADD_PRODUCT: {
		add_product(s, op.name, op.cat, 1, op.day, op.month, op.year,1);
		break;
	}
	case DELETE_PRODUCT: {
		delete_product(s, op.name, op.cat,1);
		break;
	}
	case UPDATE_PRODUCT: {
		Date* d = createDate(op.day, op.month, op.year);
		update_product(s, op.prev_name, op.prev_category, op.name, op.cat, op.quantity, d,1);
		free(d);
		break;
	}
	}

	pushUndo(op);
}

void pushUndo(Operation op) {
	if (undoTop < 99) {
		undoStack[++undoTop] = op;
	}
}

void pushRedo(Operation op) {
	if (redoTop < 99) {
		redoStack[++redoTop] = op;
	}
}