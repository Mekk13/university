#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#pragma once


Product* createProduct(char* name, char* category, int q, Date* exp_date)
{
    Product* p = (Product*)malloc(sizeof(Product));
    if (p == NULL) {
        return NULL;
    }

    
    p->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
    if (p->name == NULL) {
        free(p);
        return NULL;
    }
    setName(p, name);

    p->category = (char*)malloc(sizeof(char) * strlen(category) + 1);
    if (p->category == NULL) {
        free(p->name);
        free(p);
        return NULL;
    }
    setCategory(p, category);
    setQuantity(p, q);
    setExpDate(p, exp_date);
    return p;
}

void destroyProduct(Product* p)
{
    if (p == NULL)
        return;
    free(p->name);
    free(p->category);
    free(p);
}

void displayProduct(Product* p)
{
    Date* d = getExpDate(p);
    printf("Name: %s        Category: %s        Quantity: %d        Exp.Date: %d/%d/%d\n",p->name,p->category,p->quantity,d->day,d->month,d->year);
}

char* getName(Product* p)
{
    return p->name;
}

char* getCategory(Product* p)
{
    return p->category;
}

int getQuantity(Product* p)
{
    return p->quantity;
}

Date* getExpDate(Product* p)
{
    return &(p->exp_date);
}

void setName(Product* p, char* name)
{   
    // If the name already exists, free it
    if (p->name != NULL) {
        free(p->name);
    }

    // Allocate new memory for the name
    p->name = malloc(strlen(name) + 1); // +1 for null terminator
    if (p->name != NULL) {
        strcpy(p->name, name);  // Copy new name
    }
}

void setCategory(Product* p, char* category)
{
    // If category already exists, free it
    if (p->category != NULL) {
        free(p->category);
    }

    // Allocate new memory for the category
    p->category = malloc(strlen(category) + 1); // +1 for null terminator
    if (p->category != NULL) {
        strcpy(p->category, category);  // Copy new category
    }
}

void setQuantity(Product* p, int quantity)
{
    p->quantity = quantity;
}

void setExpDate(Product* p, Date* date)
{
    ///TODO: use getters and setters instead 
    p->exp_date.day = date->day;
    p->exp_date.month = date->month;
    p->exp_date.year = date->year;
}
