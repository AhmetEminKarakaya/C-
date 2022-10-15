#include <iostream>

using namespace std;

class Test {

	int m_a;
	int m_b;
	int* m_ptr;

public:
	//                               Constructor                               //

	Test() :m_a{ 0 }, m_b{ 0 }, m_ptr{ nullptr }
	{
		m_ptr = static_cast <int*>(malloc(sizeof(int)));

		if (m_ptr == NULL) {
			cout << "Bellek ayrilmadi\n";
			exit(1);
		}

		cout << "Constructor cagrildi\n";

	}
	//                       Destructor                        // 
	~Test() {

		if (m_ptr != NULL) {
			free(m_ptr);
		}

		cout << "Destructor cagrildi" << endl;

	}

	//                      Copy Constructor                    // 
	Test(const Test& other) :m_a{ other.m_a }, m_b{ other.m_b }{

		m_ptr = static_cast <int*>(malloc(sizeof(int)));

		if (m_ptr == NULL) {
			cout << "Bellek ayrilmadi" << endl;
			exit(1);
		}

		*m_ptr = *other.m_ptr;
		cout << "Copy Constructor cagrildi" << endl;

	}

	//                         Copy assigment                 // 

	Test& operator =(const Test& right) {

		cout << "Copy assigment cagrildi" << endl;
		if (!m_ptr) {
			free(m_ptr);
		}

		m_a = right.m_a;
		m_b = right.m_b;

		m_ptr = static_cast<int*>(malloc(sizeof(int)));

		if (m_ptr == NULL) {
			cout << "bellek ayrilamadi" << endl;
			exit(1);
		}

		*m_ptr = *right.m_ptr;

		return *this;
	}
	//                       Move Constructor                          // 

	Test(Test&& other) :m_a{ other.m_a }, m_b{ other.m_b }, m_ptr{ other.m_ptr }
	{
		cout << "Move Constructor cagrildi" << endl;
		other.m_ptr = nullptr;
	}

	//                     Move Assigment                          //

	Test& operator=(Test&& other) {
		if (!m_ptr)
			free(m_ptr);

		m_a = other.m_a;
		m_b = other.m_b;
		m_ptr = other.m_ptr;

		other.m_ptr = nullptr;

		return *this;

	}

	void set(int x, int y, int z) {

		m_a = x;
		m_b = y;
		*m_ptr = z;

	}

	void display()const {

		cout << "m_a=" << m_a << endl;
		cout << "m_b=" << m_b << endl;
		cout << "m_ptr=" << *m_ptr << endl;
	}



};











int main()
{
   
}


