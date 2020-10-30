#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct NhanSu {
	char MaNhanVien[50];
	char TenNhanVien[100];
	int GioiTinh, NamSinh, ChucVu, Luong;
	struct NhanSu *next;
};
typedef struct NhanSu *NhanVien;
//Nhap danh sach
NhanVien AddHead(NhanVien &List, char manhanvien[], char tennhanvien[], int gioitinh, int namsinh, int chucvu, int luong) {
	NhanVien p = (NhanVien)malloc(sizeof(struct NhanSu));
	strcpy(p->MaNhanVien, manhanvien);
	strcpy(p->TenNhanVien, tennhanvien);
	p->GioiTinh = gioitinh;
	p->NamSinh = namsinh;
	p->ChucVu = chucvu;
	p->Luong = luong;
	p->next = List;
	List = p;
	return List;
}
void Input(NhanVien &List) {
	int n, luongcoban;
	char manhanvien[50], tennhanvien[100];
	int gioitinh, namsinh, chucvu, luong;
	printf("Nhap luong co ban : "); scanf("%d", &luongcoban);
	printf("Nhap so luong nhan vien : "); scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("\nNhap thong tin cho nhan vien thu %d :\n", i );
		printf("Ma nhan vien : "); fflush(stdin); gets(manhanvien);
		printf("Ten nhan vien : "); fflush(stdin); gets(tennhanvien);
		printf("Gioi tinh (1 nam 0 nu) : "); scanf("%d", &gioitinh);
		printf("Nam sinh : "); scanf("%d", &namsinh);
		printf("Chuc vu : "); scanf("%d", &chucvu);
		luong = luongcoban * chucvu;   // Lương = Lương cơ bản * Chức vụ;
		AddHead(List, manhanvien, tennhanvien, gioitinh, namsinh, chucvu, luong);
	}
}
//Xuat danh sach
void Output(NhanVien List) {
	printf("\n----------------------------------------------------\nBang thong ke\n");
	printf("Ma nhan vien\t\tTen nhan vien\t\tGioi tinh\t\tNam sinh\t\tChuc vu\t\tLuong\n");
	for (NhanVien p = List; p != NULL; p = p->next) {
		printf("%12s\t\t%20s\t\t", p->MaNhanVien, p->TenNhanVien);
		if (p->GioiTinh == 1) printf("%s\t\t", "Nam" );
		else printf("%s\t\t", "Nu");
		printf("%d\t\t\t", p->NamSinh);
		switch (p->ChucVu) {
		case 1: printf("Nhan vien\t\t"); break;
		case 2: printf("Pho phong\t\t"); break;
		case 3: printf("Truong phong\t\t"); break;
		case 4: printf("Pho giam doc\t\t"); break;
		case 5: printf("Giamdoc\t\t"); break;
		}
		printf("%d\n", p->Luong);
	}
}
//Tim kiem nhan vien theo Ma nhan vien
NhanVien SearchByMS(NhanVien List, char manhanvien[]) {
	for (NhanVien p = List; p != NULL; p = p->next)
		if ( strcmp(p->MaNhanVien, manhanvien) == 0 ) return p;
	return NULL;
}
void SearchMNV(NhanVien List) {
	char manhanvien[50];
	printf("\n----------------------------------------------------\nNhap ma nhan vien can tim : "); fflush(stdin); gets(manhanvien);
	if (SearchByMS(List, manhanvien) == NULL) printf("\nKhong tim thay !\n");
	else {
		NhanVien p = SearchByMS(List, manhanvien);
		printf("\nDa tim thay, sau day la thong tin cua nhan vien can tim : \n");
		printf("%s\t%s\t%d\t%d\t%d\t%d\n", p->MaNhanVien, p->TenNhanVien, p->GioiTinh, p->NamSinh, p->ChucVu, p->Luong);
	}
}
//Dem so nhan vien Nam
void CountMale(NhanVien List) {
	int dem = 0;
	for (NhanVien p = List; p != NULL; p = p->next)
		if (p->GioiTinh == 1) dem++;
	printf("\nSo nhan vien Nam la : %d", dem);
}
//Dem so nhan vien Nu
void CountFemale(NhanVien List) {
	int dem = 0;
	for (NhanVien p = List; p != NULL; p = p->next)
		if (p->GioiTinh == 0) dem++;
	printf("\nSo nhan vien Nu la : %d", dem);
}
int main()
{
	printf("Bang chuc vu : \n");
	printf("1. Nhan vien\n2. Pho phong\n3. Truong phong\n4. Pho giam doc\n5. Giam doc\n----------------------------------------------------\n");
	NhanVien List = NULL;	
	Input(List);
	Output(List);
	SearchMNV(List);
	CountMale(List);
	CountFemale(List);
	return 0;
}