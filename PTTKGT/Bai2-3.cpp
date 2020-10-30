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
A0=1;
An=A(n-1)+1;

Suy ra O(n+1)=O(n)
*/