#include "Teacher.h"
class Department
{
	Teacher *teacher;  //Neu dung con tro thi khi huy doi tuong Department, teacher van ton tai 
	string nameDep;

public:
	Department(string = "", Teacher * = nullptr);
	~Department();
	friend ostream &operator<<(ostream &, const Department &);
};