#include <iostream>
using namespace std;
class List
{
private:
	int length;
	int *data;

public:
	List();
	List(int);
	~List();
	void Erase();
	int &operator[](int);
	int getLength() const;
	void Reallocate(int);
	void Resize(int);
	void Insert(int, int);
	void Remove(int);
	void InsertFirst(int);
	void InsertLast(int);
	friend ostream &operator<<(ostream &, const List &);
};
