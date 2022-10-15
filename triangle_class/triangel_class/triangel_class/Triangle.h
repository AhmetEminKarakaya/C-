#pragma once

#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;


class Triangle {
	float sideA, sideB, sideC;

public:
	Triangle(float a, float b, float c);
	~Triangle();
	Triangle(const Triangle& other);
	bool isTriangle(float a, float b, float c);
	float getsideA()const {
		return sideA;
	}
	float getsideB()const {
		return sideB;
	}
	float getsideC()const {
		return sideC;
	}
	void setValue(float a, float b, float c);
	bool isEquileral();
	bool isScalene();
	bool isIsosceles();
	void Triangletype();

};

Triangle::Triangle(float a, float b, float c) {
	while (!(isTriangle(a,b,c))) {
		cout << "Please enter the sides(a-b-c)" << endl;
		cin >> a >> b >> c;
	}

	sideA = a;
	sideB = b;
	sideC = c;
	cout << "Constructor cagrildi" << endl;
}
Triangle::~Triangle() {

	cout << "Destructor cagrildi" << endl;

}

Triangle::Triangle(const Triangle& other) {

	sideA = other.sideA;
	sideB = other.sideB;
	sideC = other.sideC;

	cout << "Copy constructor cagrildi" << endl;
}

void Triangle::setValue(float a, float b, float c) {
	while (!(isTriangle(a, b, c))) {
		cout << "Please enter the sides(a-b-c)" << endl;
		cin >> a >> b >> c;
	}

	sideA = a;
	sideB = b;
	sideC = c;
}

bool Triangle::isEquileral() {
	return sideA == sideB && sideB == sideC;
}

bool Triangle::isIsosceles() {
	if (isEquileral()) {
		return true;
	}

	else {
		return sideA == sideB || sideA == sideC || sideB == sideC;
	}
}

bool Triangle::isScalene() {

	return !(isEquileral);
}

void Triangle::Triangletype() {
	if (isEquileral()) {
		cout << "Esitkenar ucgen " << endl;
	}
	else if (isIsosceles()) {
		cout << "Ikizkenar ucgen" << endl;
	}
	else {
		cout << "Cesitkenar ucgen" << endl;
	}
}

bool Triangle::isTriangle(float a, float b, float c) {

	if (!(abs(b - c) < a && (a < b + c))) {
		cout << "Invalid A value" << endl;
		return false;
	}

	if (!(abs(a - c) < b && (b < a + c))) {
		cout << "Invalid A value" << endl;
		return false;
	}

	if (!(abs(a - b) < c && (c < a + b))) {
		cout << "Invalid A value" << endl;
		return false;
	}

	return true;

}