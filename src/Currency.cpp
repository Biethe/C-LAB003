#include <iostream>
#include "Currency.h"

using namespace std;

Dollar::Dollar(): value(0) {};
Dollar::Dollar(const float &v): value(v) {};
float Dollar::get_value() { return value; }

Euro::Euro(): value(0) {};
Euro::Euro(const float &v): value(v) {};
float Euro::get_value() { return value; }

Pound::Pound(): value(0) {};
Pound::Pound(const float &v): value(v) {};
float Pound::get_value() { return value; }

ostream &operator<<(ostream &o, const Dollar &d) {
	o<<d.value<<" Dollar";
	return o;
}

ostream &operator<<(ostream &o, const Euro &e) {
	o<<e.value<<" Euro";
	return o;
}

ostream &operator<<(ostream &o, const Pound &p) {
	o<<p.value<<" Pounds";
	return o;
}
