#pragma once
#include "service.h";
#include <stdio.h>
#include <string.h>

void run_all_tests();
void test_add_product(Service* s);
void test_delete_product(Service* s);
void test_update_product(Service* s);
void test_undo_redo(Service* s);
void destroy_tests(Service* s);

