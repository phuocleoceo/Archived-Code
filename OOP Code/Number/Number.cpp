#include "Number.h"
#include <iostream>
using namespace std;
Number::Number(double x)
{
    this->data = x;
}
Number::~Number()
{
}
Number::operator int(){
    return (int)(this->data);
}
Number::operator double(){
    return (double)(this->data);
}