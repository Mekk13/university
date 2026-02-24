#pragma once
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


int add_product(Service* s, char* name, char* category, int q, int day, int month, int year)
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

	r_add_product(s->repo, p,*p);

	free(d);
	return 0;
}

int delete_product(Service* s, char* name, char* category)
{
	Product* p = r_get_product_by_name_and_cat(s->repo, name, category);
	if (p == NULL) {
		return -1;
	}
	r_delete_product(s->repo, p,*p);
	return 0;
}

int update_product(Service* s, char* name, char* category,char* new_name,char* new_cat, int q, Date* d)
{
	Product* p = r_get_product_by_name_and_cat(s->repo, name, category);
	if (p == NULL) {
		return -1;
	}
	Product* new_p = createProduct(new_name, new_cat, q, d);
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
