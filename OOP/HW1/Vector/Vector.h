#include<iostream>
using namespace std;
class Vector
{
    private:
        double arr[3];
    public:
        Vector(double a,double b,double c);
        Vector operator+(const Vector& a) const;
        Vector operator+(const double& a) const;
        Vector operator*(const double& a) const;
        Vector operator-(const Vector& a) const;
        Vector operator-(const double& a) const;
        friend Vector operator*(const double& a,const Vector& b);
        friend ostream& operator<<(ostream& out,const Vector& a);
        friend Vector operator-(const double& a,const Vector& b);
};