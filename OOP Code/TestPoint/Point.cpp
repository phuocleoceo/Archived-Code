#include "Point.h"
//Constructor
Point::Point()
{
    this->xVal = 3;
    this->yVal = 3;
}
Point::Point(int xVal, int yVal)
{
    this->xVal = xVal;
    this->yVal = yVal;
}
Point::Point(int x) : xVal(x), yVal(x)
{
}
// Point::Point(const Point &p)
// {
//     this->xVal = p.xVal;
//     this->yVal = p.yVal;
// }

//Destructor
Point::~Point()
{
    cout << "Destroy Point"
         << "(" << this->xVal << " , " << this->yVal << ")" << endl;
}

//Ham binh thuong
void Point::TT(int x)
{
    xVal += x;
    yVal += x;
}
void Point::Show()
{
    cout << "xVal = " << xVal << " , yVal = " << yVal << endl;
}

void Display(Point &p)
{
    p.xVal = 5;
    p.yVal = 5;
    cout << "p.xVal = " << p.xVal << "  p.yVal = " << p.yVal << endl;
}
//Getter, Setter
int Point::get_xVal()
{
    return this->xVal;
}
void Point::set_xVal(int value)
{
    this->xVal = value;
}
int Point::get_yVal()
{
    return this->yVal;
}
void Point::set_yVal(int value)
{
    this->yVal = value;
}

// Da nang hoa toan tu nhap xuat
ostream &operator<<(ostream &o, const Point &p)
{
    o << p.xVal << "\t\t" << p.yVal << endl;
    return o;
}
istream &operator>>(istream &i, Point &p)
{
    cout << "Nhap xVal : ";
    i >> p.xVal;
    cout << "Nhap yVal : ";
    i >> p.yVal;
    return i;
}

//Da nang hoa toan tu + -
Point operator+(const Point &p1, const Point &p2)
{
    // Point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
    // return p;
    return Point(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
}
Point Point::operator-(const Point &p)
{
    Point p1(this->xVal - p.xVal, this->yVal - p.yVal);
    return p1;
}

//Phep + Class vs Int
Point operator+(const Point &p1, const int &t)
{
    Point p(p1.xVal + t, p1.yVal + t);
    return p;
}

//Da nang hoa ++
Point &Point::operator++()
{
    this->xVal++;
    this->yVal++;
    return (*this);
}
const Point Point::operator++(int)
{
    Point before = (*this);
    this->xVal++;
    this->yVal++;
    return before;
    //Luu gia tri truoc khi tang de gan cho Point khac
    //before co dia chi khac nen ko co tham chieu
    //const vi thao tac 1 chieu
}