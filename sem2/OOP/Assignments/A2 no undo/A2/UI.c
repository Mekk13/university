#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "service.h"
#include "Product.h"
#include "Date.h"
#include "repo.h"

UI* createUI(Service* s)
{
	UI* ui = malloc(sizeof(UI));
	if (ui == NULL) {
		return NULL;
	}
	ui->serv = s;
	return ui;
}

void menu() {
    printf("\n--- Smart Refrigerator Menu ---\n");
    printf("1. Add product\n");
    printf("2. Delete product\n");
    printf("3. Update product\n");
    printf("4. Display products by name contains\n");
    printf("5. Display products from a category that expire in X days\n");
    printf("6. Undo\n");
    printf("7. Redo\n");
    printf("8. extra implementation\n");
    printf("0. Exit\n");
}

void generate_10_entries(Service* s) {
    add_product(s, "Milk", "Diary", 3, 20, 4, 2025);
    add_product(s, "Cheese", "Diary", 5, 23, 4, 2025);
    add_product(s, "Chocolate", "Snack", 2, 19, 5, 2025);
    add_product(s, "Apple", "Fruit", 10, 15, 5, 2025);
    add_product(s, "Banana", "Fruit", 3, 10, 4, 2025);
    add_product(s, "Steak", "Meat", 1, 22, 3, 2025);
    add_product(s, "Sausage", "Meat", 7, 24, 3, 2025);
    add_product(s, "Egg", "Poultry", 13, 19, 5, 2025);
    add_product(s, "Zucchini", "Vegetable", 2, 19, 3, 2025);
    add_product(s, "Cake", "Snack", 1, 18, 3, 2025);
}

void handle_add(Service* s) {
    int  q, d, m, y, loop = 1;
    char name[50], cat[10];
    while (loop) {
        printf("Name: ");
        (void)scanf("%s", name);
        printf("Category: ");
        (void)scanf("%s", cat);
        printf("Quantity: ");
        (void)scanf("%d", &q);
        printf("Expiration date (dd/mm/yy): ");
        (void)scanf("%d/%d/%d", &d, &m, &y);
        add_product(s, name, cat, q, d, m, y);
        break;
    }

}

void handle_delete(Service* s) {
    char name[50], cat[10];
    printf("Name of product you wish to delete: ");
    (void)scanf("%s", name);
    printf("category of product you wish to delete: ");
    (void)scanf("%s", cat);
    delete_product(s, name, cat);
}

void handle_update(Service* s) {
    char name[50], cat[10], new_name[50], new_cat[10];
    int q, d, m, y;

    printf("Name of product you wish to update: ");
    (void)scanf("%s", name);
    printf("category of product you wish to update: ");
    (void)scanf("%s", cat);
    printf("New name: ");
    (void)scanf("%s", new_name);
    printf("New category: ");
    (void)scanf("%s", new_cat);
    printf("New quantity:");
    (void)scanf("%d", &q);
    printf("New Exp date (dd/mm/yy): ");
    (void)scanf("%d/%d/%d", &d, &m, &y);
    Date date;
    setDate(&date, d, m, y);
    int r = update_product(s, name, cat, new_name, new_cat, q, &date);
}

void handle_display_prods_that_expire_by_cat(Service* s) {
    char cat[50];
    int nre, days;
    printf("Category: ");
    (void)getchar();
    fgets(cat, 50, stdin);
    cat[strcspn(cat, "\n")] = '\0';

    printf("How many days until the product expires: ");
    (void)scanf("%d", &days);

    Product** prods = get_prods_that_expire_by_cat(s, cat, days, &nre);
    if (prods == NULL || nre == 0) {
        printf("No products found!");
        return;
    }
    for (int i = 0; i < nre; i++) {
        displayProduct(prods[i]);
    }
    free(prods);
}

void handle_display_by_name_contains1(Service* s) {
    char str[50];
    int nrf;
    printf("Name must contain: ");
    (void)getchar();  // Consume leftover newline from previous scanf
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';
    Product** sorted_prods = get_products_by_name_contains(s, str, &nrf);
    if (sorted_prods == NULL)
    {
        printf("No products found!!\n");
        return;
    }
    sort_products_bubble_desc(s, sorted_prods, nrf);
    //TODO: print function
    for (int i = 0; i < nrf; i++) {
        displayProduct(sorted_prods[i]);
    }
}


void handle_display_by_name_contains(Service* s) {
    char str[50];
    int nrf;
    printf("Name must contain: ");
    (void)getchar();  // Consume leftover newline from previous scanf
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';
    Product** sorted_prods = get_products_by_name_contains(s, str, &nrf);
    if (sorted_prods == NULL)
    {
        printf("No products found!!\n");
        return;
    }
    sort_products_merge(s, sorted_prods, nrf);
    for (int i = 0; i < nrf; i++) {
        displayProduct(sorted_prods[i]);
    }
}

int get_valid_input() {
    int choice;
    while (1) {
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input: Please enter a valid number!!!\n");
            while (getchar() != '\n'); //clear the buffer
            menu();
            printf("\nPick an action:");
        }
        else {
            return choice;
        }
    }
}


void startUI(UI* ui)
{
    while (1) {
        menu();
        int choice;
        printf("\nPick an action:");
        choice = get_valid_input();
        printf("\n");
        switch (choice) {
        case 1: {
            handle_add(ui->serv);
            break;
        }
        case 2: {
            handle_delete(ui->serv);
            break;
        }
        case 3: {
            handle_update(ui->serv);
            break;
        }
        case  4: {
            handle_display_by_name_contains(ui->serv);
            break;
        }
        case 5:
        {
            handle_display_prods_that_expire_by_cat(ui->serv);
            break;
        }
        case 6:
        {
            break;
        }
        case 8: {
            handle_display_by_name_contains1(ui->serv);
            break;
        }
        case 0: {
            printf("Exiting...\n");
            return 0;
        }
        default:
            printf("Please pick a valid option!\n");
            break;

        }
    }
}


void destroyUI(UI* ui)
{
    destroy_service(ui->serv);
    free(ui);
}