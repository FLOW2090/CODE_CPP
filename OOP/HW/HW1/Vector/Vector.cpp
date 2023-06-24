#include"Vector.h"

Vector::Vector(double a,double b,double c)
{
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
}

Vector Vector::operator+(const Vector& a) const
{
    return Vector(arr[0] + a.arr[0],arr[1] + a.arr[1],arr[2] + a.arr[2]);
}
Vector Vector::operator+(const double& a) const
{
    return Vector(arr[0] + a,arr[1] + a,arr[2] + a);
}
Vector Vector::operator*(const double& a) const
{
    return Vector(arr[0] * a,arr[1] * a,arr[2] * a);
}
Vector Vector::operator-(const Vector& a) const
{
    return Vector(arr[0] - a.arr[0],arr[1] - a.arr[1],arr[2] - a.arr[2]);
}
Vector Vector::operator-(const double& a) const
{
    return Vector(arr[0] - a,arr[1] - a,arr[2] - a);
}
Vector operator*(const double& a,const Vector& b)
{
    return b * a;
}
ostream& operator<<(ostream& out,const Vector& a)
{
    out << "(" << a.arr[0] << "," << a.arr[1] << "," << a.arr[2] << ")" << endl;
    return out;
}
Vector operator-(const double& a,const Vector& b)
{
    return b - a;
}