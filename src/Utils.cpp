#include "Utils.h"
#include "Date.h"

/*Independent function to assess the chronologic order of two given dates*/
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

/*Independent function to compute the number of days that have passed between two given dates (assuming the second passed date took place earlier in time )*/
int difference(Date d1, Date d2){
	int duration = (d1.get_day() - d2.get_day()) + (d1.get_month() - d2.get_month())*30 + (d1.get_year() - d2.get_year())*365;
	return duration;
}

/*Independent function to compute the number of days that have passed between two given dates*/
int duration(Date d1, Date d2){
	if (before(d1, d2) == false){
		return difference(d1, d2);
	}
	else{
		return difference(d2, d1);
	}
}

/*Overload of friend operator to class Date '<' which basically return the same value as function 'before'.*/
bool operator<(Date &d1,Date d2){
	return before(d1, d2);
}

/*Overload of friend operator to class Date '-' which basically return the same value as function 'difference'*/
int operator-(Date &d1,Date d2){
	return difference(d1, d2);
}

