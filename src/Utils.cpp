#include "Utils.h"
#include "Date.h"

bool before(Date d1, Date d2) {
    if (d1.get_year() < d2.get_year()) {
        return true;
    } else if (d1.get_year() == d2.get_year() && d1.get_month() < d2.get_month()) {
        return true;
    } else if (d1.get_year() == d2.get_year() && d1.get_month() == d2.get_month() && d1.get_day() < d2.get_day()) {
        return true;
    } else {
        return false;
    }
}


int difference(Date d1, Date d2){
	int duration = (d1.get_day() - d2.get_day()) + (d1.get_month() - d2.get_month())*30 + (d1.get_year() - d2.get_year())*365;
	return duration;
}

int duration(Date d1, Date d2){
	if (before(d1, d2) == false){
		return difference(d1, d2);
	}
	else{
		return difference(d2, d1);
	}
}

bool operator<(Date &d1,Date d2){
	return before(d1, d2);
}

int operator-(Date &d1,Date d2){
	return difference(d1, d2);
}

