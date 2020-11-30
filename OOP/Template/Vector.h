#include <iostream>
using namespace std;
template <class T>
class Vector
{
private:
	T *data;
	int size;

public:
	Vector(int, const T &);
	~Vector();
	void Show();
	
	// template <class U>
	// friend ostream &operator<<(ostream &, const Vector<U> &);
	
	friend ostream &operator<<(ostream &o, const Vector &v)
	{
		for (int i = 0; i < v.size; i++)
		{
			o << *(v.data + i) << "\t";
		}
	}
};