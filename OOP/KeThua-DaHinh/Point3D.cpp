#include "Point3D.h"
using namespace std;
Point3D::Point3D(int xVal, int yVal, int zVal) : Point(xVal, yVal)
{
	// this->xVal = xVal;
	// this->yVal = yVal;
	this->zVal = zVal;
}
Point3D::~Point3D()
{
	cout << "Destroy Point"
		 << "(" << this->xVal << " , " << this->yVal << " , " << this->zVal << ")" << endl;
}
void Point3D::Show3D()
{
	cout << this->xVal << "\t" << this->yVal << "\t" << this->zVal << endl;
}
void Point3D::Show()
{
	cout << this->xVal << "\t" << this->yVal << "\t" << this->zVal << endl;
}
ostream &operator<<(ostream &o, const Point3D &p)
{
	o << p.xVal << "\t\t" << p.yVal << "\t\t" << p.zVal << endl;
	return o;
}