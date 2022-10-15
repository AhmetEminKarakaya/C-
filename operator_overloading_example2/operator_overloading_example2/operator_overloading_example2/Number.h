#pragma once
#include <iostream>


class Number {
	int mx;

public:
	Number() = default;
	explicit Number(int ival) : mx{ ival } {


	}

	Number& operator+=(const Number n) {

		mx += n.mx;
		return *this;
	}
	Number& operator-=(const Number n) {

		mx -= n.mx;
		return *this;
	}

	Number& operator+=(int ival) {

		mx += ival;
		return *this;
	}
	Number& operator-=(int ival) {

		mx -= ival;
		return *this;
	}

	Number& operator++() {
		++mx;
		return *this;
	}
	Number operator++(int i) {
		Number temp = *this;
		++* this;
		return temp;

	}
	Number& operator--() {
		--mx;
		return *this;
	}
	Number operator--(int i) {
		Number temp = *this;
		--* this;
		return temp;

	}

	bool operator<(const Number& n) {

		return mx < n.mx;
	}
	bool operator==(const Number& n) {

		return mx == n.mx;
	}

	Number operator+()const {

		return *this;
	}
	Number& operator-() {
		mx *= -1;
		return *this;
	}

	bool operator<=(const Number& n1) {

		return !(n1.mx < mx);
	}
	bool operator>=(const Number& n1) {

		return !(mx < n1.mx);
	}
	bool operator!=(const Number& n1) {

		return !(mx == n1.mx);
	}
	bool operator>(const Number& n1) {

		return n1.mx < mx;
	}


	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);

	friend Number operator+(const Number& n1, int  ival);
	friend Number operator-(const Number& n1, int ival);


	friend std::ostream& operator<<(std::ostream& os, Number& n);
	friend std::istream& operator>>(std::istream& is, Number& n);

};

Number operator+(const Number& n1, const Number& n2) {

	Number result;
	result.mx = n1.mx + n2.mx;

	return result;

}
Number operator-(const Number& n1, const Number& n2) {
	Number result;
	result.mx = n1.mx - n2.mx;

	return result;
}

Number operator+(const Number& n1, int  ival) {

	Number result;

	result.mx = n1.mx + ival;
	return result;

}
Number operator-(const Number& n1, int ival) {
	Number result;

	result.mx = n1.mx - ival;
	return result;
}

std::ostream& operator<<(std::ostream& os, Number& n) {

	return os << n.mx;
}
std::istream& operator>>(std::istream& is, Number& n) {

	return is>>n.mx;
}