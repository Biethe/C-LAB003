#include<iostream>
#include<cstring>

template <class Type_currency>
class Bank_account {
	private:
		char *owner_name;
		Type_currency balance;

	public:
		Bank_account(const char *on, const Type_currency &b):balance(b) {
			owner_name = new char[strlen(on)+1];
			strcpy(owner_name, on);
		}

		Bank_account(const Bank_account &b):balance(b.get_balance()) {
			owner_name = new char[strlen(b.get_owner_name())+1];
			strcpy(owner_name, b.get_owner_name());
		}

		bool credit_balance() { return balance.get_value() > 0; }

		char *get_owner_name() { return owner_name; }

		Type_currency get_balance() { return balance; }

		friend ostream &operator<<(ostream &o, const Bank_account &b) {
			cout<<"owmer_name : "<<b.owner_name<<endl;
			cout<<"balance : "<<b.balance;
			return o;
		}
		
		~Bank_account() { delete [] owner_name; }
};

