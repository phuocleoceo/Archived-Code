#include <stdio.h>
#include<stdlib.h>
#include<time.h>
struct DSLK
{
	int data;
	struct DSLK *next;
};
typedef struct DSLK *node;
//Tạo mới Node
node CreateNode(int value) {
	node temp = (node)malloc(sizeof(struct DSLK));
	temp->data = value;
	temp->next = NULL;
	return temp;
}
//Thêm Node vào đầu danh sách
node AddToHead(node List, int value) {
	node temp = CreateNode(value);
	if (List == NULL) List = temp;
	else {
		temp->next = List;
		List = temp;
	}
	return List;
}
//Thêm Node vào cuối danh sách
node AddToTail(node List, int value) {
	node temp = CreateNode(value);
	node p;
	if (List == NULL) List = temp;
	else {
		p = List;
		while (p->next != NULL) p = p->next; //Duyệt tới cuối danh sách
		p->next = temp; //Gán nút cuối bằng temp ( next của temp bằng NULL theo hàm CreateNode)
	}
	return List;
}
//Thêm Node vào vị trí bất kì
node AddToAnyPosition(node List, int value, int position) {
	if (position == 0 || List == NULL) List = AddToHead(List, value);
	else {
		node p = List;
		int k = 1;
		while (p != NULL && k != position) {
			p = p->next;
			k++;
		}
		//Chèn vào cuối nếu position lớn hơn số lượng Node trong danh sách
		if (k != position) List = AddToTail(List, value);
		else {
			node temp = CreateNode(value);
			temp->next = p->next;
			p->next = temp;
		}
	}
	return List;
}
//Tạo L1
node CreateL1(node List, int n, int a, int b) {
	srand( (int)time(NULL) );
	for (int i = 1; i <= n; i++) List = AddToHead(List, rand() % (b - a + 1) + a);  //or AddToTail

	return List;
}
//Tạo L2
node CreateL2(node List, int n, int a, int b) {
	srand( (int)time(NULL) );
	int distance = b - a + 1; //Khoảng cách (phạm vi của n)
	int A[distance];   // Mảng có chỉ mục từ 0 -> b-a
	int i , rnd;
	for (i = a; i <= b; i++)  A[i - a] = i;  // 0 -> b-a

	for (i = 1; i <= n; i++) {
		rnd = ((double)rand() / (double)RAND_MAX) * distance;  //RandMax dc định nghĩa trong STDLIB,=32767
		List = AddToHead(List, A[rnd]);
		A[rnd] = A[distance - 1];
		distance--;
	}
	return List;
}
node CreateL(node L1, node L2) {
	if (L1 == NULL) return L2;
	node p = L1;
	while (p->next != NULL) p = p->next;
	p->next = L2;
	return L1;
}
//In ra danh sách
void ExportList(node List) {
	for (node p = List; p != NULL; p = p->next) printf("%4d ", p->data);
}
//Kiểm tra tính đơn điệu
int CheckIncrease(node List) {
	node p = List;
	for (p; p != NULL; p = p->next)
		if (p->data > p->next->data) return 0;
	return 1;
}
int CheckDecrease(node List) {
	node p = List;
	for (p; p != NULL; p = p->next)
		if (p->data < p->next->data) return 0;
	return 1;
}
void CheckMonotory(node List) {
	if (CheckIncrease(List) == 1) printf("Day so khong giam !\n");
	else if (CheckDecrease(List) == 1) printf("Day so khong tang\n");
	else printf("Day so khong tang khong giam !\n");
}
//Kiểm tra tính đối xứng, ta sẽ dùng danh sách Copy là đảo của danh sách List được tạo bằng cách AddToHead(Copy,List->data)
int CheckSymmetry(node List) {
	node Copy = NULL;
	for (node p = List; p != NULL; p = p->next) Copy = AddToHead(Copy, p->data);

	node p1 = List, p2 = Copy;
	while (p1 != NULL) {                      //or p2!=NULL
		if (p1->data != p2->data ) return 0;
		p1 = p1->next;
		p2 = p2->next;
	}
	//for(node p1=List,p2=Copy;p1!=NULL;p1=p1->next,p2=p2->next) if (p1->data != p2->data ) return 0;
	return 1;
}
void OutputSymmetry(node List) {
	if (CheckSymmetry(List) == 0) printf("Day khong doi xung !\n");
	else printf("Day so doi xung !\n");
}
//Tìm vị trí xuất hiện lần đầu của X
int SearchX(node List, int X) {
	int position = 0;
	for (node p = List; p != NULL; p = p->next) {
		if (p->data == X) return position;
		position++;
	}
	return -1; //Không tìm thấy thì trả về -1;
}
//Đếm số phần tử bằng X
int CountX(node List, int X) {
	int dem = 0;
	for (node p = List; p != NULL; p = p->next)
		if (p->data == X) dem++;
	return dem;
}
//Xoá tất cả X ra khỏi DSLK
node DeleteAllX(node List, int X) {

	while (List != NULL && List->data == X) List = List->next;

	if (List->next == NULL || List == NULL) return List;

	node p = List;
	while (p->next != NULL) {
		if (p->next->data == X) {
			p->next = p->next->next;
		}
		else p = p->next;
	}
	return List;
}

int main()
{
	int a, b, n, X, Y;
	node L1 = NULL, L2 = NULL, L = NULL;
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
	printf("\n-------------------------------------------------------------------------\n");
	printf("Danh sach L1 la : \n");
	L1 = CreateL1(L1, n, a, b);
	ExportList(L1);
	printf("\n-------------------------------------------------------------------------\n");
	printf("Danh sach L2 la : \n");
	L2 = CreateL2(L2, n, a, b);
	ExportList(L2);
	printf("\n-------------------------------------------------------------------------\n");
	printf("Danh sach L (L1 + L2) la : \n");
	L = CreateL(L1, L2);
	ExportList(L);
	printf("\n-------------------------------------------------------------------------\n");
	printf("Tinh don dieu cua day L la : ");
	CheckMonotory(L);
	printf("\n-------------------------------------------------------------------------\n");
	printf("Tinh doi xung cua day L la : ");
	OutputSymmetry(L);
	printf("\n-------------------------------------------------------------------------\n");
	printf("Nhap X : ");
	scanf("%d", &X);
	if (SearchX(L, X) == -1) {
		printf("Day L khong chua X !\n");
		printf("Thuc hien chen X-1 vao dau va X+1 vao cuoi danh sach ta duoc :\n");
		L = AddToHead(L, X - 1);
		L = AddToTail(L, X + 1);
		ExportList(L);
	}
	else {
		int position = SearchX(L, X);
		printf("Vi tri xuat hien lan dau cua X la : %d \n", position + 1);
		printf("Thuc hien chen X-1 vao truoc X va X+1 vao sau X ta duoc danh sach :\n");
		L = AddToAnyPosition(L, X - 1, position);
		L = AddToAnyPosition(L, X + 1, position + 2);
		ExportList(L);
	}

	printf("\nSo phan tu bang X co trong danh sach L la : %d", CountX(L, X) );
	printf("\n-------------------------------------------------------------------------\n");
	printf("Nhap Y de xoa no khoi danh sach L : ");
	scanf("%d", &Y);
	L = DeleteAllX(L, Y);
	ExportList(L);
	return 0;
}