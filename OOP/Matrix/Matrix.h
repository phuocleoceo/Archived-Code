#include <iostream>
using namespace std;
class Matrix
{
private:
    int **data;
    int col, row;

public:
    Matrix(int, int, int);
    ~Matrix();
    void Show();
    friend ostream &operator<<(ostream &, const Matrix &);
    int &operator()(const int &, const int &);
};