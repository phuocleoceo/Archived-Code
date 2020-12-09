#include "List.h"
int main()
{
	List arr(10);
	for (int i = 0; i < 8; i++)
		arr[i] = i + 1;
	cout << arr;
	arr.Resize(8);
	cout << arr;
	arr.Insert(0, 5);
	cout << arr;
	arr.Remove(8);
	cout << arr;
	arr.InsertFirst(0);
	cout << arr;
	arr.InsertLast(8);
	cout << arr;
	return 0;
}

// g++ List.cpp Source.cpp -std=c++11 -o a.exe ; ./a.exe