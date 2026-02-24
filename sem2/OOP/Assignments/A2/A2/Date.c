#include "Date.h"
#include <stdio.h>
#include <stdlib.h>

Date* createDate(int day, int month, int year)
{
	Date* d;
	d = (Date*)malloc(sizeof(Date));
	if (d == NULL) {
		return NULL;
	}
	d->day = day;
	d->month = month;
	d->year = year;
	return d;
}

void setDate(Date *d, int day, int month, int year)
{
	d->day = day;
	d->month = month;
	d->year = year;
}

int getDay(Date* d)
{
	return d->day;
}

int getMonth(Date* d)
{
	return d->month;
}

int getYear(Date* d)
{
	return d->year;
}

int valid_date(Date* d)
{
	///only a very simple check for now, we do not check if the month has 28/29/30/31 days
	if (getDay(d) < 1 || getDay(d) > 31)
		return 0;
	if (getMonth(d) < 1 || getMonth(d) > 12)
		return 0;
	return 1;
}
