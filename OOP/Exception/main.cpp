#include <iostream>
#include <string>
using namespace std;

double Chia(double a, double b)
{
	if (b == 0)
	{
		// throw 15;
		throw 12.3;
		// throw string("ABC");
	}
	else
	{
		return a / b;
	}
}

int main()
{
	double a = 5;
	double b = 0;
	try
	{
		double x = Chia(a, b);
		cout << x << endl;
	}
	catch (string s)
	{
		cout << "string\t" << s << endl;
	}
	catch (int e)
	{
		cout << "int\t" << e << endl;
	}
	catch (...)
	{
		cout << "Ahihi" << endl;
	};
	return 0;
}