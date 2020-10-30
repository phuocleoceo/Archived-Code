#include<stdio.h>
#include<math.h>
#include<conio.h>
#define eps 1E-3     // Độ chính xác
float F(float x[], int n, float c) {
	float p = x[0];
	for (int i = 1; i <= n; i++) p = p * c + x[i];
	return p;
}

void NhapMang(float x[], int n) {
	printf("Nhap cac he so cua p(x) : ");
	for (int i = 0; i <= n; i++) {
		scanf("%f", &x[i]);
	}
}
void ChiaDoi(float x[], int n, float a, float b, int operator) {
	printf("\nBang Ket Qua : \n\n");
	printf("\na\tb\tf((a+b)/2)\n");
	float c;
	do {
		c = (a + b) / 2;
		printf("%.3f\t%.3f\t", a, b);
		
		if ( operator*F(x, n, c) > 0) printf("+\n");
		else printf("-\n");

		if ( operator*F(x, n, c) > 0) b = c;
		else a = c;
	} while (fabs(F(x, n, c)) > eps) ;  //dùng trị tuyệt đối để rút gọn điều kiện
	printf("Nghiem cua phuong trinh la : %.3f ", c );
}
int main()
{
	int n;
	float a, b;
	char input;
	printf(" Nhap bac da thuc: "); scanf("%d", &n);
	float x[n + 1];
	NhapMang(x, n);

	do {
		do {
			printf(" Nhap khoang nghiem : ");
			scanf("%f", &a);
			scanf("%f", &b);

			if (F(x, n, a)*F(x, n, b) >= 0) printf("{ %f ; %f } khong phai Khoang Nghiem ! Nhap lai ! !\n", a, b );
		} while (F(x, n, a)*F(x, n, b) >= 0);

		int operator;
		if (F(x, n, a) < 0) operator=1; //f(b)>0
		else operator=-1;             //f(b)<0 ta chuyển sang xét -f(x)=0

		ChiaDoi(x, n, a, b, operator);
		printf("\n\n<< Nhan ESC de dung chuong trinh hoac Phim Khac de tim them nghiem ! >>\n");
		input = getch();
	} while (input != 27);

	return 0;
}