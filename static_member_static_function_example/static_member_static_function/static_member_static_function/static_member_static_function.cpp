#include <iostream>
#include "Student.h"



int main()
{
    Student s1, s2;
    std::cout << "Number of student: " << Student::get_studentcounter() << std::endl;

    {
        Student s3, s4;
        std::cout << "Number of student: " << Student::get_studentcounter() << std::endl;
    }
    std::cout << "Number of student: " << Student::get_studentcounter() << std::endl;

}

