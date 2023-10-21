#include <iostream>
#include <string>

//unvailable in std c++11
//#define T char, short int, int, long int, long long int, __int128

using namespace std;

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

template<typename T>
T factorial(unsigned int n) {
	if(n<=1) return (T)1;
	return n*factorial<T>(n-1);
}

template<typename T>
void printSizeAndFac(string type, unsigned int n, bool b) {
	size_t size = sizeof(T);
	cout<<"The size of "<<type<<" is "<<size<<" byte(s), equivalent to "<<size*8<<" bits"<<endl;
	cout<<"factorial("<<n-1<<") = "<<factorial<T>(n-1)<<endl;
	cout<<"factorial("<<n<<") = "<<factorial<T>(n)<<endl;
	cout<<"factorial("<<n+1<<") = "<<factorial<T>(n+1)<<endl;
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
	cout<<"The usigned modifier in data type is used to represent non-negative numbers only. In contrast to signed types, unsigned types can use all bits to represent the magnitude of a number since there is no need to store the sign. Its representable interval become [0, 2^(size of type)-1] instead of [-2^((size of type)-1), 2^((size of type)-1)-1]"<<endl;
	cout<<"For example, a signed char type uses one bit to represent the sign, allowing it to represent values ranging from -2^7 to 2^7-1. When using the unsigned variant of char, the range becomes [0, 2^8-1] as all 8 bits are utilized to represent the number, enhancing the positive range."<<endl;
	cout<<"Consider an int variable is assigned the value 2^7 = 128 and print it, we get: "<<(char)128<<endl;
	cout<<"due to overflow. It's the opposite of 128 because the bit used to determine the sign is set to be 1. (binary: (this bit->)1 0000 0000)"<<endl;
	cout<<"After adding the unsigned variants, we can obtain the correct value: "<<(unsigned char)128<<endl;
	cout<<endl;
	cout<<"While the unsigned data types extend the positive range by using the bit ordinarily reserved for the sign. The factorial function grows faster than the exponential increase of the storage capacity. So we will get the same result as before. Consider the examples of unsigned char and unsigned short int:"<<endl;

	f = true;
	cout<<"--unsigned char--"<<endl;
	printSizeAndFac<unsigned char>("unsigned char", 6, f);
	cout<<"--unsigned short int--"<<endl;
	printSizeAndFac<short int>("unsigned short int", 8, f);
	cout<<endl;
	cout<<"We observe that the factorial of 6 for unsigned char and of 8 for unsigned short int already result in overflows, similar to their signed counterparts."<<endl;
}

int main() {
	ex1_1();
	ex1_2();
	return 0;
}
