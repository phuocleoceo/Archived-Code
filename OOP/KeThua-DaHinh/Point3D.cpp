#include "Point3D.h"
using namespace std;
Point3D::Point3D(int xVal, int yVal, int zVal) : Point(xVal,yVal)
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
void Point3D::Show(){
	cout << this->xVal << "\t" << this->yVal << "\t" << this->zVal << endl;
}