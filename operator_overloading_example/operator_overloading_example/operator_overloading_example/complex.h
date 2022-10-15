#pragma once

#include <iostream>

using namespace std;

class ComplexNum{
	double m_img, m_real;

public:
	ComplexNum(double img = 0, double real = 0);
	ComplexNum operator+(const ComplexNum & c)const;
	void display()const;


};
