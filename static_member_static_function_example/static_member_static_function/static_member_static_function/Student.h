#include <iostream>


class Student {

	std::string m_name;
	std::string m_surname;
	static int student_counter;

public:
	Student();
	std::string get_name()const;
	std::string get_surname()const;
	Student(const std::string name, const std::string surname);
	~Student();
	static int get_studentcounter();



};
