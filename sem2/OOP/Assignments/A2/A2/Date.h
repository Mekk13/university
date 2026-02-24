#pragma once

typedef struct {
	int day, month, year;
}Date;

Date* createDate(int day, int month, int year);
void setDate(Date *d, int day, int month, int year);
int getDay(Date *d);
int getMonth(Date *d);
int getYear(Date *d);
int valid_date(Date *d);