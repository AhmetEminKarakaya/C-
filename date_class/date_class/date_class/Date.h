#pragma once
#include <string.h>
#include <iostream>

using namespace std;

class Date {
	int year, month, day;
	const int monthDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const string monthstring[12] = { "Ocak", "Subat","Mart","Nisan","Mayıs","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };

public:
	Date(int d = 1, int m = 1, int y = 1900);
	Date(const Date& other);
	~Date();
	void Setdate(int d = 1, int m = 1, int y = 1900);
	void setDay(int d);
	void setMonth(int m);
	void setyear(int y);
	int getDay()const {

		return day;
	}
	int getMonth()const {

		return month;
	}
	int getYear()const {

		return year;
	}
	void increaseday();
	void comparedate(const Date& d);
	void displayDate()const;


};

Date::Date(int d, int m , int y) {
	Setdate(d, m, y);
}

Date::~Date() {

	cout << "Destructor cagrildi" << endl;
}

Date::Date(const Date& other) {
	day = other.day;
	month = other.month;
	year = other.year;

	cout << "Copy constructor cagrildi" << endl;
}

void Date::setDay(int d) {

	if (d >= 1 && d <= monthDays[month - 1]) {
		day = d;
	}
	else {
		day = 1;
	}

}

void Date::setMonth(int m) {

	if (m >= 1 && m <= 12) {
		month = m;
	}
	else {
		month = 1;
	}
}

void Date::setyear(int y) {
	if (y >= 1900) {
		year = y;
	}
	else {
		year = 1900;
	}
}

void Date::Setdate(int d, int m , int y) {
	setMonth(m);
	setDay(d);
	setyear(y);
}

void Date::displayDate()const {
	cout << day << ":" << monthstring[month - 1] << ":" << year << endl;
}

void Date::increaseday() {

	if (day < monthDays[month - 1]) {
		day++;
	}
	else {
		day = 1;

		if (month < 12) {
			month++;
		}
		else {
			month = 1;
			year++;
		}
	}
}

void Date::comparedate(const Date& d) {

	long firsdate;
	long seconddate;

	firsdate = year * 365 + month * 30 + day;
	seconddate = d.year * 365 + d.month * 30 + d.day;

	if (firsdate > seconddate) {
		cout << "Ilk tarih daha buyuktur" << endl;
	}
	else if (seconddate > firsdate) {
		cout << "Ikinci tarih daha buyuktur" << endl;
	}
	else {
		cout << "Esittir" << endl;
	}
}