#include <iostream>
#define MAX 20
using namespace std;

int n, k, A[MAX] = {0};
static int dem = 1;
void xuat()
{
	cout << dem++ << " : ";
	for (int i = 1; i <= k; i++)
		cout << A[i] << " ";
	cout << endl;
}

void Try(int i)
{
	for (int j = 1 + A[i - 1]; j <= n - k + i; j++)
	{
		A[i] = j;
		if (i == k)
			xuat();
		else
			Try(i + 1);
	}
}

int main()
{
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;
	Try(1);
}