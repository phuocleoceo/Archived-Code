#include "Vector.h"
#include <iostream>
using namespace std;
template <class T>
Vector<T>::Vector(int n, const T &t)
{
	this->size = n;
	this->data = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		*(this->data + i) = t;
	}
}
template <class T>
Vector<T>::~Vector()
{
	delete[] this->data;
}
template <class T>
void Vector<T>::Show()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << *(this->data + i) << "\t";
	}
}
// template <class T>
// ostream &operator<<(ostream &o, const Vector<T> &v)
// {
// 	for (int i = 0; i < v.size; i++)
// 	{
// 		o << *(v.data + i) << "\t";
// 	}
// }
