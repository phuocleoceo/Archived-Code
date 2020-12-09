#include <assert.h>
#include "List.h"
List::List() : length(0), data(nullptr) {}
List::List(int length) : length(length)
{
	assert(this->length >= 0);
	if (length > 0)
		this->data = new int[this->length];
	else
		this->data = nullptr;
}
List::~List()
{
	delete[] this->data;
}
void List::Erase()
{
	delete[] this->data;
	this->data = nullptr;
	this->length = 0;
}
int &List::operator[](int index)
{
	assert(index >= 0 && index < this->length);
	return this->data[index];
}
int List::getLength() const
{
	return this->length;
}
ostream &operator<<(ostream &o, const List &l)
{
	o << "List = ";
	for (int i = 0; i < l.length; i++)
	{
		o << l.data[i];
	}
	o << endl;
	return o;
}
void List::Reallocate(int newLength)
{
	Erase();
	if (newLength <= 0)
		return;
	this->data = new int[newLength];
	this->length = newLength;
}
void List::Resize(int newLength)
{
	if (newLength == this->length)
		return;
	if (newLength <= 0)
	{
		Erase();
		return;
	}
	int *data = new int[newLength];
	if (this->length > 0)
	{
		int maxLength = (newLength > this->length) ? this->length : newLength;
		for (int i = 0; i < maxLength; i++)
			data[i] = (*this)[i];
	}
	delete[] this->data;
	this->data = data;
	this->length = newLength;
}
void List::Insert(int value, int index)
{
	assert(index >= 0 && index <= this->length);
	int *data = new int[this->length + 1];
	for (int i = 0; i < index; i++)
		data[i] = (*this)[i];
	data[index] = value;
	for (int j = index; j < this->length; j++)
		data[j + 1] = (*this)[j];
	delete[] this->data;
	this->data = data;
	++this->length;
}
void List::InsertFirst(int value)
{
	Insert(value, 0);
}
void List::InsertLast(int value)
{
	Insert(value, this->length);
}
void List::Remove(int index)
{
	assert(index >= 0 && index <= this->length);
	if (this->length == 1)
	{
		Erase();
		return;
	}
	int *data = new int[this->length - 1];
	for (int i = 0; i < index; i++)
		data[i] = (*this)[i];
	for (int j = index + 1; j < this->length; j++)
		data[j - 1] = (*this)[j];
	delete[] this->data;
	this->data = data;
	--this->length;
}


/* 
Con trỏ nhân viên trỏ về nhân viên bche or hợp đồng, đa hình đỘgn virtual

chương 1 :tham chiếU biến hằng , hàm trả về tham chiếu, cấp phát động tĩnh (mảng 1+2 chiều)
chương 2: .... hàm bạn lớp bạn , danh sách khởi tạo thành viên (hằng-tĩnh)
chương 3 : đa năng hoá hàm(hàm cùng tên) + toán tử
chương 4: 

*/