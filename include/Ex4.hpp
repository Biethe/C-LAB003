#ifndef EX4_HPP
#define EX4_HPP

#include "Currency.h"
#include "Bank_account.hpp"

template <class Type_currency>
bool check_type(Type_currency object) {
        const type_info &id = typeid(object);
        return id == typeid(Dollar) || id == typeid(Euro) || id == typeid(Pound);
}

void ex4() {
	Dollar d(100.5);
	Euro e(50);
	if(check_type(d) && check_type(e)) {
		Bank_account<Dollar> b1("Paul", d);
		cout<<b1<<endl; // test operator <<
		if(b1.credit_balance())
			cout<<"This account has a credit balance \n";
		else cout<<"This account has a debit balance \n";
		Bank_account<Euro> b2("Mark", e);
		cout<<b2<<endl;
		if(b2.credit_balance())
			cout<<"This account has a credit balance \n";
		else cout<<"This account has a debit balance \n";
	}
}

#endif
