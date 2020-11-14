#include <iostream>
#include "Point3D.h"
using namespace std;

int main()
{
	// cout << "-------------------------------------------------------------" << endl;
	// Point3D p1(4, 5, 6);
	// Point p2(20, 30);
	// p1.Show();
	// p2.Show();
	// cout << "-------------------------------------------------------------" << endl;
	// Point3D *p3d;
	// p3d = &p1;
	// p3d->Show();
	// Point *p;
	// p = &p2;
	// p->Show(); //upcast : tirnh bien dich hieu
	// cout << "-------------------------------------------------------------" << endl;
	// // trỏ p3d về p2 => mất zVal   // downcast
	// // p3d=&p2;  // lỗi
	// p = &p1;
	// p3d = static_cast<Point3D *>(&p2);
	// p->Show();  //goi ham show p2
	// p3d->Show(); //goi ham show p1 voi zVal ngau nhien
	cout << "-------------------------------------------------------------" << endl;
	Point *contro = new Point3D(2, 3, 4);
	delete contro;
	cout << "-------------------------------------------------------------" << endl;
	Point p1(2, 3);
	Point3D p2(5, 6, 7);
	cout << p1 << endl;
	cout << p2 << endl;
	cout << "-------------------------------------------------------------" << endl;
	return 0;
}