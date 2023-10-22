#include <iostream>
#include "Trip.h"
#include "Date.h"
#include "Utils.h"


	
Trip::Trip(int bd, int bm, int by, int ed, int em, int ey, float p):beg_date(bd, bm, by), end_date(ed, em, ey){
	price = p;
}

Trip::Trip(Date b, Date e, float p):beg_date(b.get_day(), b.get_month(), b.get_year()), end_date(e.get_day(), e.get_month(), e.get_year()) {
	price = p;
}

		
void Trip::print_trip() {
	int journey = duration(beg_date, this->end_date);
	std::cout << "Your trip started on " << this->beg_date.get_day() << "/" << this->beg_date.get_month()<< "/" << this->beg_date.get_year() << " and ended on " << this->end_date.get_day() << "/" << this->end_date.get_month()<< "/" << this->end_date.get_year() << "\nSo It lasted " << journey << " days." << std::endl;			
}


float Trip::price_per_day(){
	int journey = duration(beg_date, this->end_date);
	std::cout << "It cost you on average " << price/journey << " euros per day" << std::endl;
	return price/journey;
}
