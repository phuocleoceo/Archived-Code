#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SuperMarket {
	char MaSieuThi[50];
	char TenSieuThi[100];
	int NamThanhLap, DoanhSoCoBan, SoLuongNhanVien;
	struct SuperMarket *next;
};
typedef struct SuperMarket *SM;
SM AddHead(SM &List, char *code, char *name, int year, int sale, int staffnumber) {
	SM p = (SM)malloc(sizeof(SuperMarket));
	strcpy(p->MaSieuThi, code);
	strcpy(p->TenSieuThi, name);
	p->NamThanhLap = year;
	p->DoanhSoCoBan = sale;
	p->SoLuongNhanVien = staffnumber;
	p->next = List;
	List = p;
	return List;
}
void Input(SM &List) {
	int n;
	char code[50], name[100];
	int year, sale, staffnumber;
	printf("Nhap so luong sieu thi : "); scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("\nNhap thong tin cho sieu thi thu %d :\n", i );
		printf("Ma sieu thi : "); fflush(stdin); gets(code);
		printf("Ten sieu thi : "); fflush(stdin); gets(name);
		printf("Nam thanh lap : "); scanf("%d", &year);
		printf("Doanh so co ban : "); scanf("%d", &sale);
		printf("So luong nhan vien : "); scanf("%d", &staffnumber);
		List = AddHead(List, code, name, year, sale, staffnumber);
	}
}
void Output(SM List) {
	printf("Ma sieu thi\t\tTen sieu thi\t\tNam thanh lap\t\tDoanh so co ban\t\tSo luong nhan vien\n");
	for (SM p = List; p != NULL; p = p->next)
		printf("%11s\t\t%12s\t\t\t%d\t\t\t%d\t\t\t%d\n", p->MaSieuThi, p->TenSieuThi, p->NamThanhLap, p->DoanhSoCoBan, p->SoLuongNhanVien);
}
void MaxMinSale(SM List) {
	SM p = List, MAX = List, MIN = List;
	while (p != NULL) {
		if ( (p->DoanhSoCoBan) > (MAX->DoanhSoCoBan) ) MAX = p;
		if ( (p->DoanhSoCoBan) < (MIN->DoanhSoCoBan) ) MIN = p;
		p = p->next;
	}
	//dùng for cũng được
	printf("\nSieu thi co doanh so lon nhat la sieu thi %s voi doanh so %d \n", MAX->TenSieuThi, MAX->DoanhSoCoBan);
	printf("\nSieu thi co doanh so nho nhat la sieu thi %s voi doanh so %d \n", MIN->TenSieuThi, MIN->DoanhSoCoBan);
}
void MaxMinStaff(SM List) {
	SM p = List, MAX = List, MIN = List;
	while (p != NULL) {
		if ( (p->SoLuongNhanVien) > (MAX->SoLuongNhanVien) ) MAX = p;
		if ( (p->SoLuongNhanVien) < (MIN->SoLuongNhanVien) ) MIN = p;
		p = p->next;
	}
	//dùng for cũng được
	printf("\nSieu thi co so nhan vien nhieu nhat la sieu thi %s voi %d nhan vien\n", MAX->TenSieuThi, MAX->SoLuongNhanVien);
	printf("\nSieu thi co so nhan vien it nhat la sieu thi %s voi %d nhan vien \n", MIN->TenSieuThi, MIN->SoLuongNhanVien);
}
void WriteStaffToFile(SM List) {
	printf("File staffnumber.txt da duoc tao ! \n");
	FILE *f = fopen("staffnumber.txt", "w");
	SM p;
	fprintf(f, "Danh sach sieu thi co duoi 100 nhan vien : \n");
	for (p = List; p != NULL; p = p->next)
		if (p->SoLuongNhanVien < 100 ) fprintf(f, "%s\n", p->TenSieuThi);
	fprintf(f, "\nDanh sach sieu thi co tu 100 den 150 nhan vien : \n");
	for (p = List; p != NULL; p = p->next)
		if (p->SoLuongNhanVien >= 100 && p->SoLuongNhanVien <= 150) fprintf(f, "%s\n", p->TenSieuThi);
	fprintf(f, "\nDanh sach sieu thi co hon 150 nhan vien : \n");
	for (p = List; p != NULL; p = p->next)
		if (p->SoLuongNhanVien > 150 ) fprintf(f, "%s\n", p->TenSieuThi);
	fclose(f);
}
void FinalTable(SM List) {
	int Year , LCB , SLN;
	long int LoiNhuan;
	printf("Nhap nam hien tai : "); scanf("%d", &Year);
	printf("Nhap luong co ban (LCB) : "); scanf("%d", &LCB);
	printf("Nhap con so Sieu loi nhuan (SLN) : "); scanf("%d", &SLN);
	printf("\nMa sieu thi\t\tTen sieu thi\t\tDoanh so\t\tLoi nhuan\t\tDat sieu loi nhuan\n");
	for (SM p = List; p != NULL; p = p -> next) {
		printf("%11s\t\t%12s\t\t", p->MaSieuThi, p->TenSieuThi);
		printf("%d\t\t", p->DoanhSoCoBan * (Year - p->NamThanhLap) );
		LoiNhuan = p->DoanhSoCoBan - (LCB * p->SoLuongNhanVien);
		printf("%li\t\t\t", LoiNhuan );
		if (LoiNhuan > SLN ) printf("X\n");
		else printf("\n");
	}
}
void Swap(SM &a, SM &b) {
	int temp1 = a->NamThanhLap;
	a->NamThanhLap = b->NamThanhLap;
	b->NamThanhLap = temp1;
	char temp2[100];
	strcpy(temp2, a->TenSieuThi);
	strcpy(a->TenSieuThi, b->TenSieuThi);
	strcpy(b->TenSieuThi, temp2);
}
void SortByYear(SM List) {
	printf("Sap xep cac sieu thi theo thu tu tang dan cua Nam thanh lap : \n");
	if (List == NULL) return;
	SM p = List, q = NULL;
	while (p != NULL) {
		q = p->next;
		while (q != NULL) {
			if (p->NamThanhLap > q->NamThanhLap) Swap(p, q);
			q = q->next;
		}
		p = p->next;
	}
	for (p = List; p != NULL; p = p->next)
		printf("%s : %d\n", p->TenSieuThi, p->NamThanhLap );
}
int main()
{
	SM List = NULL;
	Input(List);
	printf("\n-------------------------------------------------------------------------------------------------------------------\n");
	Output(List);
	printf("\n-------------------------------------------------------------------------------------------------------------------\n");
	MaxMinSale(List);
	MaxMinStaff(List);
	printf("\n-------------------------------------------------------------------------------------------------------------------\n");
	WriteStaffToFile(List);
	printf("\n-------------------------------------------------------------------------------------------------------------------\n");
	FinalTable(List);
	printf("\n-------------------------------------------------------------------------------------------------------------------\n");
	SortByYear(List);
	return 0;
}