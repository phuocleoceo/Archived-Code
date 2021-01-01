#include<stdio.h>
#include<conio.h>
int n, j, i, x[20];
float S, M, a[20];
void tongcon()
{
	i = 1;
	x[i] = 0;
	S = 0;
	while (i > 0)
	{
		x[i] = x[i] + 1;
		if (x[i] <= n)
		{
			if (S + a[x[i]] <= M)
			{
				if (S + a[x[i]] == M)
				{
					for (j = 1; j <= i; j++)
						printf("%7.0f", a[x[j]]);
					printf("\n");
				}
				else
				{
					S = S + a[x[i]];
					x[i + 1] = x[i];
					i++;
				}
			}
		}
		else
		{
			i--; // quay lui
			S = S - a[x[i]];
		}
	}
}
int main()
{
	n = 6;
	a[1] = 50;
	a[2] = 17;
	a[3] = 73;
	a[4] = 40;
	a[5] = 33;
	a[6] = 57;
	M = 90;
	tongcon();
	getch();
	return 0;
}
