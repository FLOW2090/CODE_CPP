#include"Matrix.h"

Matrix::Matrix()
{
    col = 0;
    row = 0;
    elem = nullptr;
}

Matrix::Matrix(int _row, int _col)
{
    col = _col;
    row = _row;
}

Matrix::~Matrix()
{
    for(int i = 0;i < row;i++)
    {
        delete elem[i];
    }
    delete elem;
}

Matrix Matrix::operator+(const Matrix& matrix)
{
    Matrix tmp(row,col);
    tmp.elem = new int*[row];
    for(int i = 0;i < row;i++)
    {
        tmp.elem[i] = new int[col];
    }
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            tmp.elem[i][j] = elem[i][j] + matrix.elem[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator-(const Matrix& matrix)
{
    Matrix tmp(row,col);
    tmp.elem = new int*[row];
    for(int i = 0;i < row;i++)
    {
        tmp.elem[i] = new int[col];
    }
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            tmp.elem[i][j] = elem[i][j] - matrix.elem[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator*(const int num)
{
    Matrix tmp(row,col);
    tmp.elem = new int*[row];
    for(int i = 0;i < row;i++)
    {
        tmp.elem[i] = new int[col];
    }
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            tmp.elem[i][j] = elem[i][j] * num;
        }
    }
    return tmp;
}

Matrix Matrix::operator*(const Matrix& matrix)
{
    Matrix tmp(row,matrix.col);
    tmp.elem = new int*[row];
    for(int i = 0;i < row;i++)
    {
        tmp.elem[i] = new int[matrix.col];
    }
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < matrix.col;j++)
        {
            tmp.elem[i][j] = 0;
        }
    }
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < matrix.col;j++)
        {
            for(int k = 0;k < col;k++)
            {
                tmp.elem[i][j] += elem[i][k] * matrix.elem[k][j];
            }
        }
    }
    return tmp;
}

Matrix transpose(const Matrix& matrix)
{
    int row = matrix.col, col = matrix.row;
    Matrix tmp(row,col);
    tmp.elem = new int*[row];
    for(int i = 0;i < row;i++)
    {
        tmp.elem[i] = new int[col];
    }
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            tmp.elem[i][j] = matrix.elem[j][i];
        }
    }
    return tmp;
}

int* Matrix::operator[](int r) const
{
    return elem[r];
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
    for(int i = 0;i < matrix.row;i++)
    {
        for(int j = 0;j < matrix.col;j++)
        {
            out << matrix.elem[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Matrix& matrix)
{
    int row,col;
    in >> row >> col;
    matrix.row = row;
    matrix.col = col;
    matrix.elem = new int*[row];
    for(int i = 0;i < row;i++)
    {
        matrix.elem[i] = new int[col];
    }
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            in >> matrix.elem[i][j];
        }
    }
    return in;
}