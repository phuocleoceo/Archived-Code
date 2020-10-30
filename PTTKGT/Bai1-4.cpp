#include <iostream>
using namespace std;
bool exists = false;
void Solve(float a[], int x, int y, int value)
{
    if (x == y)
    {
        if (a[x] == value)
        {
            exists = true;
            cout << x << endl;
        }
    }
    else
    {
        Solve(a, x, (x + y) / 2, value);
        Solve(a, (x + y) / 2 + 1, y, value);
    }
}
int main()
{
    float a[] = {-10, -4, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -5, 10, -15};
    float k = 99;
    int Count = sizeof(a) / sizeof(int);
    Solve(a, 0, Count - 1, k);
    if (!exists)
        cout << "Khong ton tai " << k;
    return 0;
}

//Do phuc tap O(logn)