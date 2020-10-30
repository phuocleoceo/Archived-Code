#include <iostream>
using namespace std;
int dem = 0, sum = 0;
void Solve(int a[], int x, int y)
{
    if (x == y)
    {
        if (a[x] < 0)
        {
            dem++;
            sum += a[x];
            return;
        }
        else
            return;
    }
    else
    {
        Solve(a, x, (x + y) / 2);
        Solve(a, (x + y) / 2 + 1, y);
    }
}
int main()
{
    int a[] = {-10, -5, 1, 2};
    int Count = sizeof(a) / sizeof(int);
    Solve(a, 0, Count - 1);
    cout << "So luong so nguyen am : " << dem << endl;
    cout << "Tong cac so nguyen am do : " << sum << endl;
    return 0;
}

//Do phuc tap O(logn)