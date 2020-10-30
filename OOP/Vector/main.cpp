#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
    Vector a1(4, 5);
    Vector a2(a1);
    Vector a3 = a1;
    Vector a4;
    a4 = a1;
    return 0;
}