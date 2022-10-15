#include "Student.h"

int Student::student_counter = 0;


std::string Student::get_name()const {

	return m_name;

}

std::string Student::get_surname()const {

	return m_surname;
}

Student::Student(const std::string name, const std::string surname) : m_name{ name }, m_surname{ surname }{

	student_counter++;

}

Student::~Student() {
	student_counter--;

}

Student::Student() {

	student_counter++;
}

int Student::get_studentcounter() {

	return student_counter;
}