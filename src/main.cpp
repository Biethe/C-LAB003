#include <iostream>

using namespace std;

#include "Ex1.hpp"
//#include "Ex2.hpp"
#include "Ex3.hpp"
#include "Ex4.hpp"

int main() {
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
	cout<<"qqch"<<endl;
	//function ex2()[main in ex2.cpp] here
	cout<<endl;
	cout<<"Please type to continue."<<endl;
	cin.get();

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
