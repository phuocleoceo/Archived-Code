#include "Point.h"
//Constructor
Point::Point(int xVal, int yVal)
{
    this->xVal = xVal;
    this->yVal = yVal;
}
//Destructor
Point::~Point()
{
    cout << "Destroy Point"
         << "(" << this->xVal << " , " << this->yVal << ")" << endl;
}
void Point::Show()
{
    cout <<xVal <<"\t"<< yVal << endl;
}
// Da nang hoa toan tu nhap xuat
ostream &operator<<(ostream &o, const Point &p)
{
    o << p.xVal << "\t\t" << p.yVal << endl;
    return o;
}
