#include <iostream>
using namespace std;
float Money(int Year)
{
    if (Year == 0)
        return 6000000;
    return 1.05 * Money(Year - 1) + 100000;
}
int main()
{
    int n = 1;
    cout << "So tien luong sau " << n << "nam la : " << Money(n);
    return 0;
}

/*Do phuc tap : 
A0=1;
An=A(n-1)+1;

Suy ra O(n+1)=O(n)
*/