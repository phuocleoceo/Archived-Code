#include "SV.h"
SV::SV(int MSSV, int Age, double DTB)
    : MSSV(MSSV), Age(Age), DTB(DTB)
{
}
SV::~SV()
{
}
ostream &operator<<(ostream &o, const SV &a)
{
  o << "MSSV = " << a.MSSV
    << " , Age = " << a.Age
    << " , DTB = " << a.DTB << endl;
  return o;
}
bool SV::operator==(const SV &a)
{
  if (this->MSSV == a.MSSV && this->Age == a.Age && this->DTB == a.DTB)
    return true;
  return false;
}

int SV::getMSSV()
{
  return this->MSSV;
}