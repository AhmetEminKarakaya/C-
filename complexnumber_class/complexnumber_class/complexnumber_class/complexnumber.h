#pragma once
#include <iostream>

using namespace std;


class ComplexNumber {
	int real, image;

public:
	ComplexNumber(int r = 0, int img= 0);
	~ComplexNumber();
	ComplexNumber(const ComplexNumber& other);
	int getreal()const {
		return real;
	}
	int getimage()const {
		return image;
	}
	void setValue(int r, int img);
	ComplexNumber addComplex(const ComplexNumber& complex);
	ComplexNumber subtractComplex(ComplexNumber& complex);
	ComplexNumber multipyconstant(int constant);
	void multipyminus();
	void display()const;

};

ComplexNumber::ComplexNumber(int r, int img) {

	real = r;
	image = img;

	cout << "Constructor cagrildi" << endl;
}

ComplexNumber::~ComplexNumber() {
	cout << "Destructor cagrildi" << endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber& other) {

	real = other.real;
	image = other.image;

	cout << "Copy Constructor cagrildi" << endl;
}

void ComplexNumber::setValue(int r, int img) {

	real = r;
	image = img;
}

void ComplexNumber::display()const {

	image >= 0 ? cout << real << "+" << image << "i" << endl : cout << real << "-" << image << "i" << endl;
}

ComplexNumber ComplexNumber::addComplex(const ComplexNumber& complex) {

	ComplexNumber result;

	result.real = real + complex.real;
	result.image = image + complex.image;

	return result;
}

void ComplexNumber::multipyminus() {

	real *= -1;
	image *= -1;
}

ComplexNumber ComplexNumber::subtractComplex(ComplexNumber& complex) {

	ComplexNumber result;
	complex.multipyminus();
	result = addComplex(complex);

	return result;
}

ComplexNumber ComplexNumber::multipyconstant(int constant) {
	ComplexNumber result;
	result.real = real * constant;
	result.image = image * constant;

	return result;
}