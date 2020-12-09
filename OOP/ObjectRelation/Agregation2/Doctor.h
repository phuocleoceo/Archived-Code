#include "Patient.h"
using namespace std;
class Patient;
class Doctor
{
	string nameD;
	vector<Patient *> patient;

public:
	Doctor(string = "");
	~Doctor();
	void addPatient(Patient *);
	string getName() const;
	friend ostream &operator<<(ostream &, const Doctor &);
};