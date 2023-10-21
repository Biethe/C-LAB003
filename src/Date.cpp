#include "Date.h"
#include "Utils.h"

Date::Date(time_t t){
	struct tm t1 = *localtime(&t);
	day = t1.tm_mday;
	month = t1.tm_mon + 1;
	year = t1.tm_year + 1900;
}

Date::Date(int d, int m, int y){
	if (d <= 30 && d >=1){
		if (m<= 12 && m >= 1){
			if(y>0){
				day = d;
				month = m;
				year = y;
			}
                }
	}
	else{
		day = 1;
                month = 1;
                year = 1970;
	}
            
}

void Date::print_date(){
	switch(month){
		case 1 :
			std::cout << "The date is January " << day << ", " << year << "." << std::endl;
                    	break;
                case 2 :
                    	std::cout << "The date is February " << day << ", " << year << "." << std::endl;
                    	break;
                case 3 :
                    	std::cout << "The date is March " << day << ", " << year << "." << std::endl;
                   	break;
                case 4 :
                    	std::cout << "The date is April " << day << ", " << year << "." << std::endl;
                    	break;
                case 5 :
                    	std::cout << "The date is May " << day << ", " << year << "." << std::endl;
                    	break;
                case 6 :
                    	std::cout << "The date is June " << day << ", " << year << "." << std::endl;
                    	break;
                case 7 :
                    	std::cout << "The date is July " << day << ", " << year << "." << std::endl;
                    	break;
                case 8 :
                    	std::cout << "The date is August " << day << ", " << year << "." << std::endl;
                    	break;
                case 9 :
                    	std::cout << "The date is September " << day << ", " << year << "." << std::endl;
                    	break;
                case 10 :
                    	std::cout << "The date is October " << day << ", " << year << "." << std::endl;
                    	break;
                case 11 :
                    	std::cout << "The date is November " << day << ", " << year << "." << std::endl;
                    	break;
                case 12 :
                    	std::cout << "The date is December " << day << ", " << year << "." << std::endl;
	}
}

void Date::happy_birthday(Date b, const char *name){
	if (b.day == this -> day && b.month == this -> month){
		std::cout << "Happy birthday to you " << name << "!!"<< std::endl;
		std::cout << "You are " << this -> year - b.year << " today." << "\n" << std::endl;
	}
            
	else {
		std::cout << "Today's not your birthday " << name << "\n" << std::endl;	
	}
}

bool Date::operator<(Date d){
	return before(*this, d);
}

int Date::operator-(Date d){
	return difference(*this, d);
}

int Date::get_day(){
	return day;
}
int Date::get_month(){
	return month;
}
int Date::get_year(){
	return year;
}


