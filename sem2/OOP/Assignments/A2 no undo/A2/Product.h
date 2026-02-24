#pragma once
#include "Date.h"

typedef struct{

	char* name; //dynamic
	char* category;
	int quantity;
	Date exp_date;

}Product;

Product* createProduct(char* name, char* category, int q, Date* exp_date);
void destroyProduct(Product* p);
void displayProduct(Product* p);

char* getName(Product* p);
char* getCategory(Product* p);
int getQuantity(Product* p);
Date* getExpDate(Product* p);

void setName(Product* p, char* name);
void setCategory(Product* p, char* category);
void setQuantity(Product* p, int quantity);
void setExpDate(Product* p, Date* date);
