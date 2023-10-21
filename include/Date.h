#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <time.h>
#include <stdlib.h>

class Date{
	friend bool operator<(Date &d1,Date d2);
	friend int operator-(Date &d1,Date d2);
	private :
        	int day, month, year;
    
	public:
        	Date(int d, int m, int y);
        	Date(time_t t);        
        	void print_date();
        	void happy_birthday(Date b, const char *name);
        	bool operator<(Date b);
        	int operator-(Date d);
		int get_day();
		int get_month();
		int get_year();
};
#endif 
