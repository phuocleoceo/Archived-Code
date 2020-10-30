#include "SV.h"
class QLSV
{
private:
    SV *data;
    int n;

public:
    QLSV();
    ~QLSV();
    friend ostream &operator<<(ostream &, const QLSV &);
    //Ad sv vao cuoi mang
    void Add(const SV &);
    //Add sv vao vi tri k
    void Add(const SV &, const int &);
    //Tim sv tra ve vi tri , ko co thi tra -1
    int IndexOf(const SV &);
    //Xoa sinh vien neu tim thay
    void Remove(const SV &);
    //Xoa tai vi tri k
    void RemoveAt(const int &);
    // Lay thong tin 1 sinh vien trong Mang
    SV &operator[](const int &);
    // Update thong tin SV dua vao MSSV
    void Update(const int &);
};