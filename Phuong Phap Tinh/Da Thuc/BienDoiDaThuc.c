#include <stdio.h>
#include<conio.h>
void pycHoocner(float a[], int n, float c) {
	int k, i;
	for (k = n; k >= 1; k--)
		for (i = 1; i <= k; i++) a[i] = a[i - 1] * c + a[i];
	printf(" Cac he so cua p(y+%.0f) la : \n", c);
	for (i = 0; i <= n; i++) printf("%.0f  ", a[i] );
}
//Ham sao chep mang a vao mang b
void MangPhu(float a[],float b[],int n){
   for(int i=0;i<=n;i++) b[i]=a[i];
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
	float a[n + 1],b[n+1];
	NhapMang(a, n);
	/*Su dung Mang b copy Mang a de sua loi nhap cung gia tri 
	  cho c nhung ket qua cuoi cung cua 2 truong hop lai khac nhau */
	do {
		MangPhu(a,b,n);  
		printf(" Nhap gia tri c can tinh p(y+c): "); scanf("%f", &c);
		pycHoocner(b, n, c);
		printf("\n<Press ESC to Stop or Any Key to Continue !>\n");
		input = getch();
	} while (input != 27);  //Phím ESC có mã ASCII là 27
	return 0;
}