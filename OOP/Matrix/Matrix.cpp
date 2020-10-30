#include "Matrix.h"

Matrix::Matrix(int row, int col, int t)
    : row(row), col(col)
{
    this->data = new int *[this->row];
    for (int i = 0; i < this->row; i++)
    {
        *(this->data + i) = new int[this->col];
        for (int j = 0; j < this->col; j++)
        {
            *(*(this->data + i) + j) = t;
        }
    }
}
Matrix::~Matrix()
{
    for (int i = 0; i < this->row; i++)
    {
        delete[] * (this->data + i);
    }
    delete[] this->data;
}
void Matrix::Show()
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            // cout << *(*(this->data + i) + j) << " ";
            cout << (*this)(i, j);
        }
        cout << endl;
    }
}
ostream &operator<<(ostream &o, const Matrix &mtr)
{
    cout << "Matrix: " << endl;
    for (int i = 0; i < mtr.row; i++)
    {
        for (int j = 0; j < mtr.col; j++)
        {
            cout << *(*(mtr.data + i) + j) << " ";
            // cout << mtr(i, j) << endl;
        }
        cout << endl;
    }
    return o;
}
int &Matrix::operator()(const int &i, const int &j)
{
    static int error = -1;
    // if (i >= 0 && i < this->row)
    // {
    //     if (j >= 0 && j < this->col)
    //         return *(*(this->data + i) + j);
    // }
    // return error;
    return (i >= 0 && i < this->row && j >= 0 && j < this->col)
               ? *(*(this->data + i) + j)
               : error;
}