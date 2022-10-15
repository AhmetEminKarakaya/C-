#include "complex.h"

ComplexNum::ComplexNum(double img, double real) : m_img{ img }, m_real{ real }{


}

ComplexNum ComplexNum::operator+(const ComplexNum& c)const {

	ComplexNum result;

	result.m_img = m_img + c.m_img;
	result.m_real = m_real + c.m_real;

	return result;

}

void ComplexNum::display()const {

	cout << "image: " << m_img << " real: " << m_real<<endl;

}