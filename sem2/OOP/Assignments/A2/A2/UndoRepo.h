#pragma once

typedef enum {
	ADD_PRODUCT,
	DELETE_PRODUCT,
	UPDATE_PRODUCT
}OperationType;

typedef struct {
	OperationType type;
	char name[70], cat[70];
	int day, month, year, quantity;

	char prev_name[70], prev_category[70];
	int prev_quantity, prev_day, prev_month, prev_year;
}Operation;

extern Operation undoStack[100];
extern int undoTop;
extern Operation redoStack[100];
extern int redoTop;