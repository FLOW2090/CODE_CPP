#include <iostream>
#include <algorithm>
#include <windows.h>
#include <list>
#include <vector>
#include <deque>
#include <time.h>

using namespace std;

int main()
{
    vector<int> _vec(500000);
    list<int> _list(500000);
    deque<int> _deq(500000);
    clock_t begin, end, vec_time = 0, list_time = 0, deq_time = 0;

    for(int i = 0;i < 500000;i++)
    {
        begin = clock();
        _vec.pop_back();
        end = clock();
        vec_time += end - begin;
    }

    for(int i = 0;i < 500000;i++)
    {
        begin = clock();
        _list.pop_back();
        end = clock();
        list_time += end - begin;
    }

    for(int i = 0;i < 500000;i++)
    {
        begin = clock();
        _deq.pop_back();
        end = clock();
        deq_time += end - begin;
    }

    cout << "vector back pop:" << vec_time << endl;
    cout << "list back pop:" << list_time << endl;
    cout << "deque back pop:" << deq_time << endl;

    return 0;
}