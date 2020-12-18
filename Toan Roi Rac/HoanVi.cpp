#include <iostream>
#define MAX 20
using namespace std;

int n, USED[MAX] = {0}, A[MAX];
//0 chưa dùng , 1 đã dùng		//Lưu hoán vị vào mảng A
static int dem = 1;
void xuat()
{
	cout << dem++ << " : ";
	for (int i = 1; i <= n; i++)
		cout << A[i] << " ";
	cout << endl;
}

void Try(int i)
{
	for (int j = 1; j <= n; j++)
	{
		//Kiểm tra nếu phần tử chưa được chọn thì sẽ đánh dấu
		if (!USED[j])
		{
			A[i] = j;	 // Lưu một phần tử vào hoán vị
			USED[j] = 1; //Đánh dấu đã dùng
			if (i == n)	 //Kiểm tra nếu đã chứa một hoán vị thì xuất
				xuat();
			else
				Try(i + 1);
			USED[j] = 0;
		}
	}
}

int main()
{
	cout << "Nhap n: ";
	cin >> n;
	Try(1);
}