#include "DVAC.h"
#include "DVAT.h"
#include <iostream>
using namespace std;
int main()
{
	DVAC p;
	DV *p1 = &p;
	p1->An();
	DVAT q;
	p1 = &q;
	p1->An();
	return 0;
}