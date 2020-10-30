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
	printf("Nhap cac he so trong can cua g(x) : ");
	for (int i = 0; i <= n; i++) {
		scanf("%f", &x[i]);
	}
}
void LoopToResult(float x[], int n, float a, float can) {
	printf("\nBang Ket Qua : \n\n");
	printf("x\tg(x)\n");
	float b;
	do {
		b = a;
		// a =   exp( (1 / can) * log(F(x, n, b)) );   // Tính căn bậc của hàm g(x), log là ln
		a = pow(F(x, n, b), 1.0 / can);
		printf("%.3f\t%.3f\n", b, a);
	}	while ( (fabs(a - b) >= eps) && (fabs(a - b) <= 1.0 / eps));

	if (fabs(a - b) < eps) printf("\nVay nghiem cua phuong trinh la : %.3f ", a ); //hoặc b
	else printf("\nHam g(x) khong thoa man dieu kien Hoi tu !");
}
int main()
{

	int n;
	float a, can;
	char input;
	printf(" Nhap bac ham cua phan trong can cua g(x) : "); scanf("%d", &n);
	float x[n + 1];
	NhapMang(x, n);
	printf("Nhap bac can cho g(x) : "); scanf("%f", &can);

	do {
		printf("Nhap a sao cho a thuoc khoang nghiem cua f(x) ( x=g(x) ) : ");
		scanf("%f", &a);

		LoopToResult(x, n, a, can);

		printf("\n\n<< Nhan ESC de dung chuong trinh hoac Phim Khac de tim them nghiem ! >>\n");
		input = getch();
	} while (input != 27);

	return 0;
}
