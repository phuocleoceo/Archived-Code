#include <stdio.h>
#include<conio.h>
#define MAX 10
void nhap(float y[], int n) {
	for (int i = 0; i <= n; i++) {
		printf("y[%d] = ", i );
		scanf("%f", &y[i]);
	}
}
void NewTon(float a[][MAX], float y[], int &n) {
	int i, j;
	printf("Nhap n : "); scanf("%d", &n);
	printf("Nhap gia tri ham tai %d moc noi suy : \n", n + 1 );
	nhap(y, n);
	for (i = 0; i <= n; i++) a[i][0] = y[i];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++) a[i][j] = a[i][j - 1] - a[i - 1][j - 1];
	printf("\nBang sai phan thu duoc la :\n");
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= i; j++) printf("%10.3f   ", a[i][j]);
		printf("\n");
	}
}
int main() {
	float a[MAX][MAX], y[MAX];
	int n;
	char stop;
	do {
		NewTon(a, y, n);
		printf("\nNhan ESC de dung lai >< Phim bat ky de tiep tuc\n");
		stop = getch();
	} while (stop != 27);

	return 0;
}