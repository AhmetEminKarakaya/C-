#pragma once

#include <string.h>
#include <iostream>

using namespace std;

class Person {
protected:
	string personname, personsurname;
public:
	Person(string name = "", string surname = "") {
		personname = name;
		personsurname = surname;
	}
	string getPersonname()const { return personname; }
	string getPersonsurname()const { return personsurname; }
	void setPersonname(string name) {
		personname = name;
	}
	void setPersonsurname(string surname) {
		personsurname = surname;
	}
	void print() {
		cout << "Name:" << personname << endl;
		cout << "Surname:" << personsurname << endl;
	}
};

class Student : public Person {

	int studentID, studentgrade;
	bool passorFail;
public:
	//Student();
	Student(string name, string surname, int ID) : Person(name, surname) {
		studentID = ID;

	}
	int getStudentID()const { return studentID; }
	void setStudentID(int ID) { studentID = ID; }
	int getStudentGrade()const { return studentgrade; }
	void setStudentGrade(int grade) { studentgrade = grade; }
	int getpassorfail()const { return passorFail; }
	void setpassorfail(bool passorfail) { passorFail = passorfail; }
	void print() {
		Person::print();
		cout << "ID:" << studentID << endl;
		cout << "Grade:" << studentgrade << endl;
		
	}
};

class Teacher : public Person {

	string department;

public:
	Teacher(string name, string surname, string dep) : Person(name, surname) {
		department = dep;
	}
	string getDepartment()const { return department; }
	void setDepartment(string dep) { department = dep; }
	void print() {
		Person::print();
		cout << "Departmnet:" << department;
	}
	void passFailStatus(Student* studentarray);
};

void Teacher::passFailStatus(Student* studentarray) {
	float average = 0.0;
	for (int i = 0; i < sizeof(studentarray); i++) {
		average += studentarray[i].getStudentGrade();
	}
	average = (float)average / sizeof(studentarray);
	cout << "Class average:" << average << endl;

	for (int i = 0; i < sizeof(studentarray); i++) {

		if (studentarray[i].getStudentGrade() >= average) {
			studentarray[i].setpassorfail(true);
		}
		else {
			studentarray[i].setpassorfail(false);
		}
	}
}