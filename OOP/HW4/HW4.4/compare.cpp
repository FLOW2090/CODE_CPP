#include "compare.h"
#include <math.h>

bool CompareInt_1::compare(int a,int b)
{
    return (a < b);
}

bool CompareInt_2::compare(int a,int b)
{
    int c = 0,d = 0;
    int cpya = a,cpyb = b;
    for(int i = 0;i < 3;i++)
    {
        c += a % 10;
        a /= 10;
        d += b % 10;
        b /= 10;
    }
    if(c == d) return (cpya < cpyb);
    return (c < d);
}

bool ComparePoint_1::compare(Point a,Point b)
{
    if(a.x == b.x) return (a.y < b.y);
    return (a.x < b.x);
}

bool ComparePoint_2::compare(Point a,Point b)
{
    int disa = pow(a.x,2) + pow(a.y,2),disb = pow(b.x,2) + pow(b.y,2);
    if(disa == disb)
    {
        if(a.x == b.x) return (a.y < b.y);
        return (a.x < b.x);
    }
    return (disa < disb);
}

AbstractCompare<int>* get_compare_int(int type)
{
    switch(type){
        case 1:
        {
            auto *tmpa = new CompareInt_1();
            return tmpa;
        }
        case 2:
        {
            auto *tmpb = new CompareInt_2();
            return tmpb;
        }
        default:
            break;
    }
}

AbstractCompare<Point>* get_compare_point(int type)
{
    switch(type){
        case 3:
        {
            auto *tmpa = new ComparePoint_1();
            return tmpa;
        }
        case 4:
        {
            auto *tmpb = new ComparePoint_2();
            return tmpb;
        }
        default:
            break;
    }
}