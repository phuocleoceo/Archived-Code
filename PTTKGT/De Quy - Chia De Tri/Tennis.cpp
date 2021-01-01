#include <iostream>
using namespace std;
int n, i, j;
int A[129][128];
void Tennis(int n)
{
	int m, i, j, x;
	if (n == 2)
	{
		A[1][1] = 2;
		A[2][1] = 1;
	}
	else
	{
		m = n / 2;
		Tennis(m); // vung 1 tren trai
		for (i = m + 1; i <= n; i++)
			for (j = 1; j <= m - 1; j++)
				A[i][j] = A[i - m][j] + m; // vung 2 duoi trai
		for (i = 1; i <= m; i++)
			for (j = m; j <= n - 1; j++)
			{
				x = i + j;
				if (x > n)
					x = x - m;
				A[i][j] = x; // vung 3 tren phai
				A[x][j] = i; // vung 4 duoi phai
			}
	}
}
void Print()
{
	for (int j = 0; j <= n; j++)
		A[0][j] = j;
	for (int i = 0; i <= n; i++)
		A[i][0] = i;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n - 1; j++)
			cout << "\t" << A[i][j];
		cout << endl;
	}
}
int main()
{
	n = 8;
	Tennis(n);
	Print();
	return 0;
}