#include <iostream>
using namespace std;
class SV
{
private:
    int MSSV;
    int Age;
    double DTB;

public:
    SV(int = 1, int = 1, double = 0.1);
    ~SV();
    friend ostream &operator<<(ostream &, const SV &);
    //Ham da nang hoa de so sanh 2 sinh vien
    bool operator==(const SV &);
    // getter
    int getMSSV();
};