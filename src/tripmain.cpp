/*#include "Date.h"
#include "Trip.h"


int main(int argc, char *argv[]){
	
	if (argc != 7){
		std::cout << "Please enter 6 parameters in the command line \n(The first 3 of them corresponding to the beginning date of your trip, and the remaining 3 corresponding to the end date of your trip.)" << std::endl;
		std::cout << "They should all be integers and be passed as in the following format 'DD MM YY'" << std::endl;
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
	return 0;
}
*/
