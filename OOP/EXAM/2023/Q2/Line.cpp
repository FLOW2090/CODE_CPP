#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class Line{
public:
    T k;
    T b;
    Line(T _k,T _b = 0) : k(_k), b(_b){}
    template <class T1>
    bool intersect(const Line<T1>& line){
        if(k == line.k && b == line.b) return true;
        return (k != line.k);
    }
    void show(){
        cout << k << ',' << b << endl;
    }
    template <class T2>
    bool operator < (const Line<T2>& line){
        return k < line.k;
    }
};

template <class T>
class Point{
public:
    T x;
    T y;
    Point(T _x,T _y) : x(_x), y(_y){}
    void move(T dx,T dy){
        x += dx;
        y += dy;
    }
    void show(){
        cout << '(' << x << ',' << y << ')' << endl;
    }
    bool check(const Line<T>& l){
        return (y - l.k * x == l.b);
        //return (double(y) - double(l.k) * double(x) - double(l.b) < 1e-6 || double(l.k) * double(x) + double(l.b) - double(y) < 1e-6);
    }
};