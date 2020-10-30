#include <stdio.h>
#define MAX 20
void Floyd(int A[][MAX], int n)
{
	int i, j, k;
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (A[i][j] > A[i][k] + A[k][j])
					A[i][j] = A[i][k] + A[k][j];
}
void Input(int A[][MAX], int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			printf("Nhap A[%d][%d] : ", i, j);
			scanf("%d", &A[i][j]);
		}
}
void Output(int A[][MAX], int n)
{
	printf("\nKet qua : \n");
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
}
int main()
{
	int A[MAX][MAX], n;
	printf("Nhap n : ");
	scanf("%d", &n);
	Input(A, n);
	Floyd(A, n);
	Output(A, n);
	return 0;
}