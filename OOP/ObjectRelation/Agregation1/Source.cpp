#include <iostream>
#include "Department.h"
int main()
{
	Teacher *t = new Teacher("NVA", 40);
	{
		Department d("CNTT", t);
		cout << d; // d chi ton tai trong khoi Code
	}
	cout << *t;
	delete t;
	return 0;
}

// g++ Teacher.cpp Department.cpp Source.cpp -std=c++11 -o a.exe ; ./a.exe