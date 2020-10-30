#include <stdio.h>
#include<conio.h>
float pxHoocner(float a[], int n, float c) {
	float p = a[0];
	for (int i = 1; i <= n; i++) p = p * c + a[i];
	return p;
}

void NhapMang(float a[], int n) {
	printf("Nhap cac he so cua p(x) : ");
	for (int i = 0; i <= n; i++) {
		scanf("%f", &a[i]);
	}
}
int main()
{
	int n;
	float c;
	char input;
	printf(" Nhap bac da thuc: "); scanf("%d", &n);
	float a[n + 1];
	NhapMang(a, n);
	do {
		printf(" Nhap diem tinh: "); scanf("%f", &c);
		printf("Gia tri cua ham p(%.0f) la : %.3f \n", c, pxHoocner(a, n, c ) );
		printf("Press ESC to Stop or Any Key to Continue !\n");
		input = getch();
	} while (input != 27);  //Phím ESC có mã ASCII là 27
	return 0;
}