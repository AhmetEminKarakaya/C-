#include <iostream>
#include "complex.h"





int main()
{

    ComplexNum c1{ 20,30 };
    ComplexNum c2{ 10,20 };
    ComplexNum c3;

    c3.display();

    c3 = c1 + c2;

    c3.display();
    
}

