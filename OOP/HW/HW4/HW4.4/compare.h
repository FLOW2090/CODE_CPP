#pragma once

#include "abstract_compare.h"
#include "point.h"

class CompareInt_1 : public AbstractCompare<int>
{
    bool compare(int a,int b) override;
};
class CompareInt_2 : public AbstractCompare<int>
{
    bool compare(int a,int b) override;
};
class ComparePoint_1 : public AbstractCompare<Point>
{
    bool compare(Point a,Point b) override;
};
class ComparePoint_2 : public AbstractCompare<Point>
{
    bool compare(Point a,Point b) override;
};

AbstractCompare<int>* get_compare_int(int type);
AbstractCompare<Point>* get_compare_point(int type);