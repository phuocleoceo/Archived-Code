#include "Point3D.h"
#include <iostream>
#include <string>
#include<exception>
using namespace std;
double Chia(double a, double b)
{
	if (b == 0)
	{
		// throw Point3D(1, 2, 3);
		 throw string("y khong the bang 0 !");
	}
	else
	{
		return a / b;
	}
}
int main()
{
	double x;
	double y;
	bool success;
	do
	{
		success = true;
		cout << "Nhap x : ";
		cin >> x;
		cout << "Nhap y : ";
		cin >> y;
		try
		{
			double z = Chia(x, y);
			cout << z << endl;
		}
		catch (string &s)
		{
			cout << s << endl;
			success = false;
		}
		catch (Point3D e)
		{
			cout << "Point3D\t\t" << e << endl;
		}
		// Dung & cho Doi tuong or String de giu nguyen kieu khi chuyen tiep ngoai le (throw)
		// luc nay bien cap phat tinh dc giai phong , bien cap phat dong thi khong
		catch (Point &e)
		{
			cout << "Point\t\t" << e << endl;
			throw;
		}
		catch (...)
		{
			cout << "Ahihi" << endl;
		};
	} while (success == false);

	return 0;
}

// Hàm dựng ko cần bắt xử lý
// Hàm huỷ ko nên phát sinh ngoại lệ , nếu có cần chặn bắt tất cả , nếu ko sẽ throw-> main => Ứng dụng crash lúc nào không biết