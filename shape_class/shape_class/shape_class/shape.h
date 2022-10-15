#pragma once

#include <iostream>
#define pi  3.14159265

using namespace std;

class Shape {

	double shapeArea;
	double shapeCircumference;

public:
	double getArea()const { return shapeArea; }
	double getCircumference()const { return shapeCircumference; }
	void setArea(double area) { shapeArea = area; }
	void setCircumference(double circumference) { shapeCircumference = circumference; }
	virtual void calculatorArea() = 0;
	virtual void calculatorPerimeter() = 0;
	virtual void display() = 0;

};

class Circle : public Shape {

	double radius;

public:
	Circle(double r) {
		radius = r;
	}
	void calculatorArea() {
		double area = pi * pow(radius, 2);
		setArea(area);
	}
	void calculatorPerimeter() {
		double circum = 2 * pi * radius;
		setCircumference(circum);
	}
	void display() {
		cout << "Circle Information" << endl;
		cout << "Radius: " << radius << endl;
		cout << "Perimeter: " << getCircumference() << endl;
		cout << "Area: " << getArea() << endl;
	}
};

class Rectangle : public Shape {

	double width, height;

public:
	Rectangle(double w, double h) {
		width = w;
		height = h;
	}
	void calculatorArea() {
		double area = width * height;
		setArea(area);
	}
	void calculatorPerimeter() {
		double circum = 2 * (width + height);
		setCircumference(circum);
	}

	void display() {

		cout << "Width:" << width << endl;
		cout << "Height:" << height << endl;
		cout << "Area: " << getArea() << endl;
		cout << "Perimeter:" << getCircumference() << endl;


	}

};