#ifndef EX1_HPP
#define EX1_HPP

#include <string>

//unvailable in std c++11
//#define T char, short int, int, long int, long long int, __int128

void remainderOf10Rec(ostream &o, __int128 d) {
	if(d>0) {
		__int128 k = d/10;
		remainderOf10Rec(o, k);
		o<<(int)(d-k*10);
	}
}

ostream &operator<<(ostream &o, const char &c) { o<<(int)c; return o; }

ostream &operator<<(ostream &o, const unsigned char &c) { o<<(int)c; return o; }

ostream &operator<<(ostream &o, const __int128 &c) {
	if(c==0) o<<c;
	else {
		__int128 d = c;
		if(d<0) { d = -d; o<<"-"; }
		remainderOf10Rec(o, d);
	}
	return o;
}

ostream &operator<<(ostream &o, const unsigned __int128 &c) {
	if(c==0) o<<c;
	else {
		__int128 d = c;
		if(d<0) { d = -d; o<<"-"; }
		remainderOf10Rec(o, d);
	}
	return o;
}

template<typename T>
T factorial(unsigned int n) {
	if(n<=1) return (T)1;
	return n*factorial<T>(n-1);
}

template<typename T>
void printSizeAndFac(string type, unsigned int n, bool b) {
	size_t size = sizeof(T);
	T fac = factorial<T>(n-1);
	cout<<"The size of "<<type<<" is "<<size<<" byte(s), equivalent to "<<size*8<<" bits"<<endl;
	cout<<"factorial("<<n-1<<") = "<<fac<<endl;
	cout<<"factorial("<<n<<") = "<<fac*n<<endl;
	cout<<"factorial("<<n+1<<") = "<<fac*n*(n+1)<<endl;
	cout<<"The result of factorial in type "<<type<<" overflow when n > "<<n-1;
	cout<<", because "<<n-1<<"!<2^";
	(!b)?(cout<<"("<<size*8<<"-1)") : (cout<<size*8);
	cout<<"-1<"<<n<<"!"<<endl;
}

void ex1_1() {
	cout<<"==================="<<endl;
	cout<<"*      Ex1.1      *"<<endl;
	cout<<"==================="<<endl;

	for(int i=0; i<15; i++){
		cout<<"i = "<<i<<", ";
		cout<<i<<"! = "<<factorial<int>(i)<<endl;
	}
	cout<<"Factorial results overflow when n>12, because int type only has 4 bytes = 32 bits in C/C++, so the int variables can only present the value within the range [-2^31, 2^31-1], equivalent to [-214783648, 214783647]. Given that 13! is larger than 2^31-1, it exceeds the presentational capacity of a 32-bit integer, resulting in an overflow."<<endl;
}

void ex1_2() {
	cout<<"==================="<<endl;
	cout<<"*      Ex1.2      *"<<endl;
	cout<<"==================="<<endl;
	
	bool f = false; //unsigned flag
	cout<<"--char--"<<endl;
	printSizeAndFac<char>("char", 6, f);
	cout<<"--short int--"<<endl;
	printSizeAndFac<short int>("short int", 8, f);
	cout<<"--int--"<<endl;
	printSizeAndFac<int>("int", 13, f);
	cout<<"--long int--"<<endl;
	printSizeAndFac<long int>("long int", 21, f);
	cout<<"--long long int--"<<endl;
	printSizeAndFac<long long int>("long long int", 21, f);
	cout<<"--__int128--"<<endl;
	printSizeAndFac<__int128>("__int128", 34, f);

	cout<<endl;
	
	f = true;
	cout<<"--unsigned char--"<<endl;
	printSizeAndFac<unsigned char>("unsigned char", 6, f);
	cout<<"--unsigned short int--"<<endl;
	printSizeAndFac<unsigned short int>("unsigned short int", 8, f);
	
	cout<<"--unsigned int--"<<endl;
	printSizeAndFac<unsigned int>("unsigned int", 13, f);
	cout<<"--unsigned long int--"<<endl;
	printSizeAndFac<unsigned long int>("unsigned long int", 21, f);
	cout<<"--unsigned long long int--"<<endl;
	printSizeAndFac<unsigned long long int>("unsigned long long int", 21, f);
	cout<<"--unsigned __int128--"<<endl;
	printSizeAndFac<unsigned __int128>("unsigned __int128", 34, f);
}

#endif
