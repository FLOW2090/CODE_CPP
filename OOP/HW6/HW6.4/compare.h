#pragma once
#include <vector>
#include <functional>
#include <list>
#include "sortlevel.h"
using namespace std;

template <class T>
class Compare
{
    private:
        vector<function<bool(T,T)>> comp;
    public:
        friend Compare<vector<int>> make_comp(list<sort_level> sortlevels);
        Compare() = default;
        Compare(const initializer_list<function<bool(T,T)>> _list)
        {
            for(auto com : _list)
            {
                comp.push_back(com);
            }
        }
        Compare(const vector<function<bool(T,T)>> vec)
        {
            comp = vec;
        }
        bool operator () (T a,T b)
        {
            for(int i = 0;i < comp.size();i++)
            {
                if(comp[i](a,b))
                {
                    return true;
                }
                else if(comp[i](b,a))
                {
                    return false;
                }
            }
        }
};