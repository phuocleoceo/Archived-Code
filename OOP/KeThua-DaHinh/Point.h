#include <iostream>
using namespace std;
class Point
{
protected:
    int xVal;
    int yVal;

public:
    Point(int, int);
    ~Point();
    virtual void Show();  // Hàm ảo , Point3D kế thừa lại nên Ảo luôn
    //con trỏ trỏ đến đối tượng nào sẽ gọi đúng Hàm của đối tượng đó, không bị mất hay sinh giá trị rác
    friend ostream &operator<<(ostream &, const Point &);
};