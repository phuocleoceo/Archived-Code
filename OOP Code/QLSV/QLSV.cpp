#include "QLSV.h"
//Constructor and Destructor
QLSV::QLSV()
{
    this->n = 0;
    this->data = NULL;
}
QLSV::~QLSV()
{
    delete[] this->data;
}
//Overload
ostream &operator<<(ostream &o, const QLSV &db)
{
    o << "DSSV : " << endl;
    for (int i = 0; i < db.n; i++)
    {
        o << "Sinh vien thu " << i << " : ";
        o << *(db.data + i);
    }
    return o;
}
SV &QLSV::operator[](const int &i)
{
    static SV *error = NULL; //con tro error kieu sinh vien
    return (i >= 0 && i < this->n) ? *(this->data + i) : *error;
}
//Add SV
void QLSV::Add(const SV &s)
{
    if (this->n == 0)
    {
        this->data = new SV[this->n + 1];
        this->data[this->n] = s;
    }
    else
    {
        // Tạo mảng tạm mới bằng mảng cũ
        SV *temp = new SV[this->n];
        //Sao chép các giá trị mảng cũ vào mảng mới
        for (int i = 0; i < this->n; i++)
        {
            *(temp + i) = *(this->data + i);
        }
        // Xoá mảng cũ
        delete[] this->data;
        // Tạo lại mảng cũ nhưng kích thước + 1
        this->data = new SV[this->n + 1];
        // Sao chép giá trị từ mảng tạm vào mảng cũ
        for (int i = 0; i < this->n; i++)
        {
            *(this->data + i) = *(temp + i);
        }
        // Gán phần tử cuối mảng cũ bằng Sinh Viên
        this->data[this->n] = s;
    }
    // Tăng kích thước mảng cũ lên 1
    this->n++;
}
void QLSV::Add(const SV &s, const int &k)
{
    // Trường hợp mảng chưa có gì thì coi như tạo mới và thêm vào đầu
    if (this->n == 0)
    {
        this->data = new SV[this->n + 1];
        this->data[this->n] = s;
    }
    else if (k >= this->n)
    {
        //Trường hợp k lớn hơn n-1 thì xem như thêm vào cuối mảng
        Add(s);
        //Do hàm Add(s) đã có lệnh this->n++ nên ta giảm nó đi(kết thúc hàm này đã có this->n++)
        this->n--;
    }
    else
    {
        //Mảng phụ lưu mảng hiện tại
        SV *temp = new SV[this->n];
        for (int i = 0; i < this->n; i++)
        {
            *(temp + i) = *(this->data + i);
        }
        //Xoá mảng hiện tại rồi cấp phát với size tăng thêm 1
        delete[] this->data;
        this->data = new SV[this->n + 1];
        //Gán vị trí k cho sinh viên s
        this->data[k] = s;
        //Chỉ số từ 0->k-1, nếu k=0 thì vòng lặp này ko chạy
        for (int i = 0; i < k; i++)
        {
            *(this->data + i) = *(temp + i);
        }
        //Chỉ số từ k + 1 -> n ,
        //trừ 1 ở mảng temp vì mảng data đã thêm sinh viên s vào rồi nên chỉ số 2 bên lệch nhau 1
        for (int i = k + 1; i <= this->n; i++)
        {
            *(this->data + i) = *(temp + i - 1);
        }
    }
    this->n++;
}
//Search
int QLSV::IndexOf(const SV &s)
{
    for (int i = 0; i < this->n; i++)
    {
        if (*(this->data + i) == s)
            return i;
    }
    return -1;
}
//Remove
void QLSV::Remove(const SV &s)
{
    int k = IndexOf(s);
    if (k == -1)
        cout << "Khong tim thay nen khong the xoa ! " << endl;
    else
    {
        SV *temp = new SV[this->n];
        for (int i = 0; i < this->n; i++)
        {
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new SV[this->n - 1]; // Luc nay chi so data : 0 -> n-2
        for (int i = 0; i < k; i++)
        {
            *(this->data + i) = *(temp + i);
        }
        for (int i = k; i < this->n - 1; i++)
        {
            *(this->data + i) = *(temp + i + 1); //lệch 1
        }
        this->n--;
    }
}
void QLSV::RemoveAt(const int &k)
{
    if (k < 0 || k >= this->n - 1)
    {
        cout << "Chi so k khong hop le, khong the xoa !" << endl;
    }
    else //Neu viet ham RemoveAt truoc thi co the dung lai no o ham Remove
    {
        SV *temp = new SV[this->n];
        for (int i = 0; i < this->n; i++)
        {
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new SV[this->n - 1]; // Luc nay chi so data : 0 -> n-2
        for (int i = 0; i < k; i++)
        {
            *(this->data + i) = *(temp + i);
        }
        for (int i = k; i < this->n - 1; i++)
        {
            *(this->data + i) = *(temp + i + 1); //lệch 1
        }
        this->n--;
    }
}
//Update bang MSSV
void QLSV::Update(const int &MSSV)
{
    int position = -1;
    //Tim sinh vien do
    for (int i = 0; i < this->n; i++)
    {
        if ((*this)[i].getMSSV() == MSSV)
            position = i;
    }
    //
    if (position == -1)
    {
        cout << "Khong tim thay MSSV nay ! " << endl;
    }
    else
    {
        int newMSSV, newAge;
        double newDTB;
        cout << "Nhap MSSV moi : ";
        cin >> newMSSV;
        cout << "Nhap Age moi : ";
        cin >> newAge;
        cout << "Nhap DTB moi : ";
        cin >> newDTB;
        SV newSinhVien(newMSSV, newAge, newDTB);
        RemoveAt(position);
        Add(newSinhVien, position);
    }
}