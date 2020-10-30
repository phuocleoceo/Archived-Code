#include "TG.h"
#include<iostream>
using namespace std;
TG::TG(int xA, int yA, int xB, int yB, int xC, int yC)
    : A(xA, yA), B(xB, yB), C(xC, yC)
{
}
void TG::ShowTG()
{
    (this->A).Show();
    (this->B).Show();
    (this->C).Show();
}
TG::~TG()
{
    cout<<"Delete TG"<<endl;    
}
