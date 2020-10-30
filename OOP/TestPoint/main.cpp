#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    // Point p3 = p1 + p2; // Point p3= operator+(p1 , p2);
    // p3.Show();
    //
    // Point p4 = p1 - p2; // Point p4= p1.operator-(p2);
    // p4.Show();
    //
    // Point p1(5, 2);
    // cin >> p1;
    //
    // Point p2 = p1 + 1;
    // cout << p2;
    //
    // Point p3 = 1 + p1;
    // Point p3 = Point(1) + p1; //da nang hoa constructure
    //
    // operator<<(cout, p1);
    //
    Point p1(5, 2);
    Point p4 = p1++;
    cout << p1 << p4;
    return 0;
}