#ifndef TRIP_H
#define TRIP_H
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Date.h"


class Trip{
	private:
		Date beg_date, end_date;
		float price;
	public:
		Trip(int bd, int bm, int by, int ed, int em, int ey, float p);
		Trip(Date b, Date e, float p);
		void print_trip();
		float price_per_day();
};
#endif
