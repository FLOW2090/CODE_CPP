#pragma once
#include <vector>

using std::vector;

template <class T>
class Instruction
{
public:
    int position;
    T value;
    virtual void apply(std::vector<int> &vec) = 0;
    virtual void apply(std::vector<double> &vec) = 0;
    virtual void output() = 0;
};

