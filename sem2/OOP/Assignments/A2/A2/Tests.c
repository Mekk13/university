#pragma once
#include "Tests.h"
#include <assert.h>

void run_all_tests()
{
	Repository* repo = create_repo();
	Service* serv = create_service(repo);

	test_add_product(serv);
	test_delete_product(serv);
	test_update_product(serv);
	test_undo_redo(serv);
	printf("All tests passed!\n");
	destroy_tests(serv);
}

void destroy_tests(Service* s) {
	destroy_service(s);
}

void test_add_product(Service* s)
{
	printf("Testing add..\n");
	assert(add_product(s, "egg", "poultry", 2, 12, 9, 2022,1)==0);
	Product* p = r_get_product_by_name_and_cat(s->repo, "egg", "poultry");
	assert(strcmp(getCategory(p), "poultry") == 0);
	assert(strcmp(getName(p), "egg") == 0);
	assert(getQuantity(p) == 2);
	Date* d = getExpDate(p);
	assert(getDay(d) == 12);
	assert(getMonth(d) == 9);
	assert(getYear(d) == 2022);

	delete_product(s, "egg", "poultry",1);
	delete_product(s, "egg", "poultry",1);
}

void test_delete_product(Service* s)
{
	printf("Testing delete..\n");
	add_product(s, "egg", "poultry", 1, 12, 9, 2022,1);
	assert(delete_product(s, "egg", "poultry",1)==0);
	assert(r_get_product_by_name_and_cat(s->repo, "egg", "poultry") == NULL);

	add_product(s, "egg", "poultry", 2, 12, 9, 2022,1);
	assert(delete_product(s, "egg", "poultry",1) == 0);
	Product* p = r_get_product_by_name_and_cat(s->repo, "egg", "poultry");
	assert(getQuantity(p) == 1);
	delete_product(s, "egg", "poultry",1);

}

void test_update_product(Service* s)
{
	printf("Testing update..\n");
	add_product(s, "egg", "poultry", 1, 12, 9, 2022,1);
	Date* d = createDate(1, 1, 1111);
	update_product(s, "egg", "poultry", "milk", "diary", 1,d,1);
	Product* p = r_get_product_by_name_and_cat(s->repo, "milk", "diary");
	assert(p != NULL);
	assert(strcmp(getName(p), "milk") == 0);
	assert(strcmp(getCategory(p), "diary") == 0);
	assert(getQuantity(p) == 1);

	Date* d1 = getExpDate(p);
	assert(getDay(d1) == 1);
	assert(getMonth(d1) == 1);
	assert(getYear(d1) == 1111);

}


void test_undo_redo(Service* s)
{
	printf("Testing undo...\n");
	add_product(s, "y", "y", 1, 12, 9, 2022,1);
	undo(s);
	Product* p = r_get_product_by_name_and_cat(s->repo, "y", "y");
	assert(p == NULL);
	redo(s);
	Product* p1 = r_get_product_by_name_and_cat(s->repo, "y", "y");
	assert(p1 != NULL);
	
}
