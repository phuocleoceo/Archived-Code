#include "Number.h"
#include <iostream>
using namespace std;
int main()
{
    Number n(1.2);
    cout << int(n); //trong C++ thi (int)n giong int(n)
                    //double x=p; thi x=1.2 vi ham double() tu dong duoc goi , giong nhu int x=3.5 => x=3
    return 0;
}