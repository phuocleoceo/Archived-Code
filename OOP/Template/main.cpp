#include "Vector.cpp"
#include <iostream>
using namespace std;
int main()
{
	Vector<int> a(3, 5);
	a.Show();
	cout << endl;
	cout << a;
	return 0;
}