#include <iostream>
#include "Patient.h"
#include "Doctor.h"
using namespace std;
int main()
{
	Patient *p1 = new Patient("Dave");
	Patient *p2 = new Patient("Frank");
	Patient *p3 = new Patient("Betsy");
	Doctor *d1 = new Doctor("James");
	Doctor *d2 = new Doctor("Scott");
	d1->addPatient(p1);
	d2->addPatient(p1);
	d2->addPatient(p3);
	cout << *d1;
	cout << *d2;
	cout << *p1;
	cout << *p2;
	cout << *p3;
	delete p1;
	delete p2;
	delete p3;
	delete d1;
	delete d2;
	return 0;
}


//Quan he nhieu nhieu
// g++ Patient.cpp Doctor.cpp Source.cpp -std=c++11 -o a.exe ; ./a.exe