#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void DayL1(int x[], int n, int a, int b) {
	srand( (int)time(NULL) );   // Hàm giúp các lần chạy sau không trùng với lần 1,ép kiểu time từ t_time về int
	for (int i = 0; i < n; i++) x[i] = rand() % (b - a + 1) + a;
}
void DayL2(int y[], int n, int a, int b) {
	srand( (int)time(NULL) );
	int distance = b - a + 1; //Khoảng cách (phạm vi của n)
	int A[distance];   // Mảng có chỉ mục từ 0 -> b-a
	int i , rnd;
	for (i = a; i <= b; i++)  A[i - a] = i;  // 0 -> b-a

	for (i = 0; i < n; i++) {
		rnd = ((double)rand() / (double)RAND_MAX) * distance;  //RandMax dc định nghĩa trong STDLIB,=32767
		y[i] = A[rnd];
		A[rnd] = A[distance - 1];
		distance--;
	}
}
void GopDay(int x[], int y[], int n, int z[]) {
	for (int i = 0; i < n; i++) z[i] = x[i];
	for (int i = n; i < (2 * n); i++) z[i] = y[i - n];
}
void XuatDS(int a[], int n) {
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
}
//Hàm xét dãy hằng số
int DayHang(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		if (a[i] != a[i + 1]) return 0;
	return 1;
}
// Hàm xét tính tăng dần , nếu đúng trả 1 , sai trả 0
int TangDan(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) return 0;
	}
	return 1;
}
// Hàm xét tính giảm dần , nếu đúng trả 1 , sai trả 0
int GiamDan(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1]) return 0;
	}
	return 1;
}
//Kết hợp 2 hàm Tăng Giảm để rút ra kết quả cuối cùng
void TinhDonDieu(int a[], int n) {
	if (DayHang(a, n) == 1) printf("Day la Day Hang ! \n");
	else if ( TangDan(a, n) == 1 ) printf("Day so tang dan !\n");
	else if ( GiamDan(a, n) == 1 ) printf("Day so giam dan !\n"); //nếu không tăng thì hoặc là giảm hoặc ktangkgiam, phải xét tiếp hàm GiamDan
	else printf("Day so khong tang khong giam !\n");
}

int TinhDoiXung(int a[], int n) {
	for (int i = 0; i < n / 2; i++)
		if (a[i] != a[n - 1 - i]) return 0;
	return 1;
}

int FindX(int a[], int n, int X) {
	int flag = -1;
	for (int i = 0; i < n; i++)
		if (a[i] == X) {
			flag = i;
			break;
		}
	return flag;
}
//Hàm chèn khi không tìm thấy X trong L
void ChenI(int a[], int &n, int X) {
	//Chèn X-1 vào đầu dãy
	for (int j = n; j > 0; j--) a[j] = a[j - 1];
	a[0] = X - 1;
	n++;
	//Chèn X+1 vào cuối dãy
	a[n] = X + 1;
	n++;
}
//Hàm chèn khi tìm thấy X trong L
void ChenII(int a[], int &n, int X, int vitri) {
	//Chèn X-1 vào trước X, dời từ X đến cuối mảng sang phải 1 ô rồi chèn X-1 vào vị trí cũ của X
	for (int j = n; j > vitri - 1; j--) a[j] = a[j - 1];
	a[vitri] = X - 1;
	n++;
	//Chèn X+1 vào sau X, lúc này X ở ô (vitri+1), ta dời các phần tử phía sau X sang phải 1 ô rồi chèn vào ngay sau X giá trị X+1
	for (int j = n; j > vitri + 1; j--) a[j] = a[j - 1];
	a[vitri + 2] = X + 1;
	n++;
}
int CountY(int a[], int n, int Y) {
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == Y) dem++;
	return dem;
}

void DeleteX(int a[], int &n, int X) {
	for (int i = 0; i < n ; i++) {
		if (a[i] == X) {
			for (int j = i; j < n; j++) a[j] = a[j + 1];  //ở đây có lỗi hình thành a[n] nhưng không ảnh hưởng
			n--;

			i--;  //Trường hợp 2 giá trị kề nhau đều bằng X,nếu không xét lại a[i] đó thì sẽ bỏ xót
		}
	}
}
int main() {	//đưa hàm srand vào main cũng được
	int a, b, n;
	printf("Nhap khoang [a ; b] : \n");
	do {
		printf("Nhap a (a > 0) : "); scanf("%d", &a);
		if (a <= 0) printf("Nhap lai !\n");
	} while (a <= 0);

	do {
		printf("Nhap b (0<b<1000) : ");
		scanf("%d", &b);
		if (b <= 0 || b >= 1000) printf("Nhap lai !\n");
	} while (b <= 0 || b >= 1000);

	do {
		printf("Nhap n ( n < %d ) : ", b - a); scanf("%d", &n);
		if (n >= (b - a)) printf("Nhap lai !\n");
	} while (n >= (b - a));
	//n<= b-a+1 mới đủ để chứa các phần tử
	printf("-------------------------------------------------------------------------------------------------\n");

	int x[n];  // Mảng lưu dãy L1
	DayL1(x, n, a, b);
	printf("Day L1 la : \n");
	XuatDS(x, n);

	printf("\n-------------------------------------------------------------------------------------------------\n");

	int y[n];  //Mảng lưu dãy L2
	DayL2(y, n, a, b);
	printf("Day L2 la : \n");
	XuatDS(y, n);

	printf("\n-------------------------------------------------------------------------------------------------\n");
	int m = 2 * n;
	int z[m];
	printf("Gop 2 day L1 va L2 ta duoc day L la : \n");
	GopDay(x, y, n, z);
	XuatDS(z, m);

	printf("\n-------------------------------------------------------------------------------------------------\n");
	printf("Kiem tra tinh don dieu cua day L : ");
	TinhDonDieu(z, m );
	printf("\n-------------------------------------------------------------------------------------------------\n");
	printf("Kiem tra tinh doi xung cua day L : ");
	if (TinhDoiXung(z, m ) == 0) printf("Day L khong doi xung !\n");
	else printf("Day L doi xung !\n");
	printf("\n-------------------------------------------------------------------------------------------------\n");
	int X;
	printf("Nhap X : ");  scanf("%d", &X);
	if (FindX(z, m, X) == -1) {
		printf("%d khong ton tai trong day L !\n", X );
		printf("Thuc hien viec chen X-1 vao dau day va X+1 vao cuoi day ta thu duoc day L la :\n");
		ChenI(z, m, X);
		XuatDS(z, m);
	}

	else {
		int vitri = FindX(z, m, X) + 1 ;
		printf("%d ton tai trong day L va xuat hien lan dau tien o vi tri thu %d \n", X, vitri);
		printf("Thuc hien viec chen X-1 vao truoc X va X+1 vao sau X ta thu duoc day L la :\n");
		ChenII(z, m, X, vitri - 1); // trả lại đúng chỉ số của X trong mảng
		XuatDS(z, m);
	}
	printf("\n-------------------------------------------------------------------------------------------------\n");
	int Y;
	printf("Nhap Y : "); scanf("%d", &Y);
	printf("Day L co %d phan tu co gia tri bang %d \n", CountY(z, m, Y), Y );
	printf("\n-------------------------------------------------------------------------------------------------\n");
	printf("Nhap X de xoa no ra khoi Day L : "); scanf("%d", &X);
	DeleteX(z, m, X);
	XuatDS(z, m);
	printf("\n-------------------------------------------------------------------------------------------------\n");
	return 0;
}
/*Khoảng ở đây có lấy bằng ( đoạn )
Kết hợp phép chia lấy dự
Random 1 số trong khoảng a đến b
int n = rand() % (b – a + 1) + a;
Có thể sử dụng thêm hàm srand()
trong thư viện time để random theo thời gian.
Chứ ko thì hàm rand() tắt đi random lại vẫn số cũ
-Hàm srand có tác dụng sinh sô ngẫu nhiên cho rand từ hạt giống được chọn ,
và hạt giống ngẫu nhiên thích hợp nhất chính là thời gian của hệ thống
*/