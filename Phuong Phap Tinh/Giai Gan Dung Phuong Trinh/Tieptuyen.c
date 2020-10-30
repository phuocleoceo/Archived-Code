#include<stdio.h>
#include<math.h>
#include<conio.h>
#define eps 1E-3     // Độ chính xác
//Thay doi ham f(x) o day
float f(float x) {
	return exp(x) - 10 * x + 7;
}
//Thay doi ham fdh(x) o day
float fdh(float x) {
	return exp(x) - 10;
}
void TiepTuyen(float x) {
	printf("\nBang Ket Qua : \n");
	printf("\nx\tf(x)/fdh(x)\n");
	float y;
	do {
		y = x;
		x = y - f(x) / fdh(x);
		printf("%.3f\t%.3f\n", y, y - x); //b-a= F/FDH
	} while (fabs(x - y) > eps);
	printf("\nNghiem cua phuong trinh la : %.3f ", x);   //Hoặc y
}
int main()
{
	float x;
	char input;
	do {
		printf("Nhap x0 thuoc khoang nghiem f(x) : ");
		scanf("%f", &x);
		TiepTuyen(x);
		printf("\n\n<< Nhan ESC de dung chuong trinh hoac Phim Khac de tim them nghiem ! >>\n");
		input = getch();
	} while (input != 27);

	return 0;
}