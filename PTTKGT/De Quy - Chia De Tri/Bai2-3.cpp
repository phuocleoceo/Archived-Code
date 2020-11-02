#include <iostream>
using namespace std;
float Money(int Year)
{
    if (Year == 0)
        return 400000;
    return 1.1 * Money(Year - 1);
}
int main()
{
    int Year = 20;
    cout << "So tien phai tra sau 20 nam la : " << Money(Year);
    return 0;
}

/*Do phuc tap : 
A(n)=A(n-1)+1; (ton 1 cho lenh return)
A(n-1)=A(n-2)+1
..............
A(2)=A(1)+1
A(1)=A(0)+1
A(0)=1

Cong ve theo ve A(n)=n+1
Suy ra O(n+1)=O(n)
*/