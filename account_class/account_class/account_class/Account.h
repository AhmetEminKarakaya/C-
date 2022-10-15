#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class Account {

	float account_balance;
	string personname, personsurname, personphone;

public:

	Account(string name, string surname, float balance = 0, string phonenumber = " ");
	Account(const Account& other);
	~Account();
	bool controlnameorsurname(string nameorsurname);
	bool controlphonenumber(string phonenumber);
	void displayprofile();
	void credit(float);
	void withdraw(float);
	void sendmoney(Account& othaccount, float money);
	void setPersonname(string name);
	void setPersonsurname(string surname);
	void setPersonphone(string phone);
	void setpersonbalance(float balance = 0);
	int getpersonbalance()const {
		return account_balance;
	}
	string getpersonname()const {
		return personname;
	}
	string getpersonsurname()const {
		return personsurname;
	}
	string getpersonphone()const {
		return personphone;
	}

};

Account::Account(string name, string surname, float balance = 0, string phonenumber = " ") {

	setPersonname(name);
	setPersonsurname(surname);
	setpersonbalance(balance);
	setPersonphone(phonenumber);

}

Account::~Account() {
	cout << "Destructor cagrildi" << endl;
}

Account::Account(const Account& other) {
	personname = other.personname;
	personsurname = other.personsurname;
	personphone = other.personphone;
	account_balance = other.account_balance;
}

bool Account::controlnameorsurname(string nameorsurname) {

	for (unsigned i = 0; i < nameorsurname.length(); i++) {

		if (!((nameorsurname.at(i) >= 'A' && nameorsurname.at(i) <= 'Z') || (nameorsurname.at(i) >= 'a' && nameorsurname.at(i) <= 'z'))) {
			return false;
		}
	}
	return true;
}

bool Account::controlphonenumber(string phonenumber) {

	if (phonenumber.empty()) {
		return true;
	}

	if (phonenumber.length() != 11) {
		return false;
	}

	for (unsigned int i = 0; i < phonenumber.length(); i++) {

		if ((!(phonenumber.at(i) >= '0') && (phonenumber.at(i) <= '9'))) {
			return false;
		}
	}

	return true;
}

void Account::setPersonname(string name) {

	while (!controlnameorsurname(name)) {
		cout << "Gecersiz isim tekrar deneyin" << endl;
		cin >> name;
	}
	personname = name;
}

void Account::setPersonsurname(string surname) {
	while (!controlnameorsurname(surname)) {
		cout << "Gecersiz soyisim tekrar deneyin" << endl;
		cin >> surname;
	}
	personsurname = surname;
}

void Account::setPersonphone(string phone) {
	while (!controlphonenumber(phone)) {
		cout << "Gecersiz phone tekrar deneyin" << endl;
		cin >> phone;
	}
	personphone = phone;
}

void Account::setpersonbalance(float balance) {
	if (balance < 0) {
		account_balance = 0;
	}
	else {
		account_balance = balance;
	}
}

void Account::credit(float amount) {

	while (amount <= 0) {
		cout << "Yanlis miktar. Tekrar girin" << endl;
		cin >> amount;
	}

	account_balance += amount;
}

void Account::withdraw(float amount) {

	while (amount <= 0 || amount > account_balance) {
		cout << "Yanlis miktar. Tekrar girin" << endl;
		cin >> amount;
	}

	account_balance -= amount;
}

void Account::displayprofile() {

	cout << "Name:" << personname << " Surname:" << personsurname << endl;

	if (!personphone.empty()) {
		cout << "Phone:" << personphone << endl;
	}

	else {
		cout << "Phone: None" << endl;
	}

	cout << "Balance:" << account_balance << endl;
}

void Account::sendmoney(Account& othaccount, float money) {
	while (amount <= 0 || amount > account_balance) {
		cout << "Yanlis miktar. Tekrar girin" << endl;
		cin >> amount;
	}

	account_balance -= money;
	othaccount.account_balance += money;
}