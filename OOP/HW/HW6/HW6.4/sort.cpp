#include <iostream>
#include <list>
#include <vector>
#include "compare.h"
#include "sortlevel.h"
using namespace std;

Compare<vector<int>> make_comp(list<sort_level> sortlevels)
{
    vector<function<bool(vector<int>,vector<int>)>> func;
    for(auto sortlevel : sortlevels)
    {
        int i = sortlevel.column - 1;
        switch (sortlevel.order)
        {
            case ASCEND:
                func.push_back([i](vector<int> a,vector<int> b) { return a[i] < b[i]; });
                break;
            case DESCEND:
                func.push_back([i](vector<int> a,vector<int> b) { return a[i] > b[i]; });
                break;
            default:
                break;
        }
    }
    Compare<vector<int>> comp(func);
    return comp;
}
