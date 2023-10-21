#ifndef MONEY_H
#define MONEY_H

#include <iostream>

using namespace std;

class Dollar {
	private: float value;
	public:
		Dollar();
		Dollar(const float &v);
		float get_value();
		friend ostream &operator<<(ostream &o, const Dollar &d); 
};

class Euro {
	private: float value;
	public:
		Euro();
		Euro(const float &v);
		float get_value();
		friend ostream &operator<<(ostream &o, const Euro &d); 
};

class Pound {
	private: float value;
	public:
		Pound();
		Pound(const float &v);
		float get_value();
		friend ostream &operator<<(ostream &o, const Pound &d); 
};

#endif
