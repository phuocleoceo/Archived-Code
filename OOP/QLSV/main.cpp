#include <iostream>
#include "QLSV.h"
using namespace std;
int main()
{
    QLSV db;
    SV a(4, 5, 6.54);
    SV b(6, 7, 9.6);
    SV c(7, 8, 9.6);
    db.Add(a);
    db.Add(b);
    db.Add(c);
    SV d(1, 2, 3);
    db.Add(d, 3);
    //Xuat mang
    cout << db;
    cout << "---------------------------------------" << endl;
    //Tim kiem
    int search = db.IndexOf(b);
    if (search == -1)
        cout << "Khong tim thay !" << endl;
    else
        cout << "Tim thay tai vi tri " << search << endl;
    cout << "\n---------------------------------------" << endl;
    //Remove
    SV e(10, 5, 6);
    // db.Remove(e);
    // db.Remove(a);
    db.RemoveAt(8);
    db.RemoveAt(1);
    cout << "Sau khi xoa ta co " << db;
    cout << "\n---------------------------------------" << endl;
    // operator []
    cout << db[1];
    cout << "\n---------------------------------------" << endl;
    // Update
    int MSSVUpdate;
    cout << "Nhap MSSV can Update : ";
    cin >> MSSVUpdate;
    db.Update(MSSVUpdate);
    cout << db;
    return 0;
}