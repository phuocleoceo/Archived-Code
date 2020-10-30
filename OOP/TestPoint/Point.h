#include<iostream>
using namespace std;
class Point
{
private:
    int xVal;
    int yVal;

public:
    Point();
    Point(int);
    Point(int, int);  //Neu dung doi so mac dinh thi Point(int) khong bao gio duoc goi
    // Point(const Point &);
    ~Point();
    void TT(int);
    void Show();
    int get_xVal();
    void set_xVal(int);
    int get_yVal();
    void set_yVal(int);
    friend void Display(Point &);
    friend Point operator+(const Point &, const Point &);
    Point operator-(const Point &);
    friend ostream& operator<<(ostream&,const Point&);
    friend istream& operator>>(istream&,Point&);  //Thay doi nen remove Const
    friend Point operator+(const Point &, const int &);
    //prefix  (++x)
    Point& operator++();
    //postfix x++
    const Point operator++(int);
};