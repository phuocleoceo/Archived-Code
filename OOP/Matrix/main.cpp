#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix a(2, 2, 3);
    cout<<a(1,4);
    cout<<endl;
    a.Show();
    return 0;
}