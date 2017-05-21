#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static int daytab[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*
 * Rewrite the routines day_of_year and month_day with pointers instead of indexing.
 */
int main(void) {
	printf("day_of_year(1993, 7, 1): %d\n", day_of_year(1993, 7, 1));
	int month = 1, day = 0;
	month_day(1993, 182, &month, &day);
	printf("month_day(1993, 182): month = %d, day = %d\n", month, day);
	return 0;
}

int day_of_year(int year, int month, int day) {
	int *p, leap, days, i;
	leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	days = 0;
	i = 0;
	p = &daytab[leap][1];
	for (i = 1; i < month; i++) {
		days += *p;
		p++;
	}
	return days + day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
	int leap, *p;
	leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	p = &daytab[leap][1];
	while (yearday > *p) {
		(*pmonth)++;
		yearday -= *p;
		p++;
	}
	*pday = yearday;
}