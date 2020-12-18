#include <iostream>
#define MAX 20
using namespace std;

int n, k, USED[MAX] = {0}, A[MAX];
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
	for (int j = 1; j <= n; j++)
	{
		if (!USED[j])
		{
			A[i] = j;
			USED[j] = 1;
			if (i == k)
				xuat();
			else
				Try(i + 1);
			USED[j] = 0;
		}
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