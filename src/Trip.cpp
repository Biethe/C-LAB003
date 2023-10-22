#include <iostream>
#include "Trip.h"
#include "Date.h"
#include "Utils.h"


/*Constructor1*/
Trip::Trip(int bd, int bm, int by, int ed, int em, int ey, float p):beg_date(bd, bm, by), end_date(ed, em, ey){
	price = p;
}

/*Constructor 2*/
Trip::Trip(Date b, Date e, float p):beg_date(b.get_day(), b.get_month(), b.get_year()), end_date(e.get_day(), e.get_month(), e.get_year()) {
	price = p;
}

/*Member function for printing trip duration*/		
void Trip::print_trip() {
	int journey = duration(beg_date, this->end_date);
	std::cout << "\nYour trip started on " << this->beg_date.get_day() << "/" << this->beg_date.get_month()<< "/" << this->beg_date.get_year() << " and ended on " << this->end_date.get_day() << "/" << this->end_date.get_month()<< "/" << this->end_date.get_year() << "\nSo It lasted " << journey << " days." << std::endl;			
}

/*Member function for computing daily average of expenses during the trip*/
float Trip::price_per_day(){
	int journey = duration(beg_date, this->end_date);
	std::cout << "\nIt cost you on average " << price/journey << " euros per day" << std::endl;
	return price/journey;
}
