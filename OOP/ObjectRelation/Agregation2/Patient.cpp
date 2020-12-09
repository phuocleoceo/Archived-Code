#include "Patient.h"
Patient::Patient(string name) : nameP(name)
{
}
Patient::~Patient() {}
ostream &operator<<(ostream &o, const Patient &t)
{
	o << t.nameP << endl;
	return o;
}
void Patient::addDoctor(Doctor *d)
{
	this->doctor.push_back(d);
}
string Patient::getName() const
{
	return this->nameP;
}