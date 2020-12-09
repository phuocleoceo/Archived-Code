#include <iostream>
#include <string>
#include <vector>
#pragma once
// #include "Doctor.h"
using namespace std;
class Doctor;
class Patient
{
	private:
		string nameP;
		vector<Doctor *> doctor;
		void addDoctor(Doctor *);

	public:
		Patient(string = "");
		~Patient();
		string getName() const;
		friend ostream &operator<<(ostream &, const Patient &);
		friend class Doctor;
};