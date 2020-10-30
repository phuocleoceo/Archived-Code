#include <iostream>
using namespace std;

class Vector
{
private:
    int *data;
    int size;
public:
    Vector(int = 2, int = 1);
    Vector(const Vector &);
    ~Vector();
    void Show();
    friend ostream &operator<<(ostream &, const Vector &);
    int &operator[](const int &);
    const Vector &operator=(const Vector &);
};