#include <iostream>

using namespace std;

#include "Ex1.hpp"
#include "Trip.h"
#include "Ex3.hpp"
#include "Ex4.hpp"

int main(int argc, char *argv[]) {
	cout<<"==================="<<endl;
	cout<<"*       Ex1       *"<<endl;
	cout<<"==================="<<endl;
	ex1_1();
	cout<<endl;
	cout<<"Please type to continue."<<endl;
	cin.get();
	ex1_2();
	cout<<endl;
	cout<<"Please type to continue."<<endl;
	cin.get();
	
	cout<<"==================="<<endl;
	cout<<"*       Ex2       *"<<endl;
	cout<<"==================="<<endl;
	if (argc != 7){
		std::cout << "\nPlease enter 6 arguments in the command line." << std::endl;
		std::cout << "\nThe first 3 of them corresponding to the beginning date of your trip, and the remaining 3 corresponding to the end date of your trip." << std::endl;
		std::cout << "\nThey should all be integers and be passed as in the following format 'DD MM YY'" << std::endl;
		std::cout << "\nAn example would be './main 12 01 2018 07 05 2019'"<< std::endl;
	}
	else{
		float price;
		std::cout << "May you enter the overall price of the trip:" << std::endl;
		std::cin >> price;
		int beg_d = atoi(argv[1]);
		int beg_m = atoi(argv[2]);
		int beg_y = atoi(argv[3]);
		int end_d = atoi(argv[4]);
		int end_m = atoi(argv[5]);
		int end_y = atoi(argv[6]);
		Trip trip_1(beg_d, beg_m, beg_y, end_d, end_m, end_y, price);
		trip_1.print_trip();
		trip_1.price_per_day();
		
	}

	cout<<"==================="<<endl;
	cout<<"*       Ex3       *"<<endl;
	cout<<"==================="<<endl;
	ex3(); //function ex3()[main in ex3.cpp] here
	cout<<endl;
	cout<<"Please type to continue."<<endl;
	cin.get();
	
	cout<<"==================="<<endl;
	cout<<"*       Ex4       *"<<endl;
	cout<<"==================="<<endl;
	ex4();

	return 0;
}
