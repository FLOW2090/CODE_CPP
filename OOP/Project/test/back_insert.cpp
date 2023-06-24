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
    vector<int> _vec;
    list<int> _list;
    deque<int> _deq;
    clock_t begin, end, vec_time = 0, list_time = 0, deq_time = 0;

    for(int i = 0;i < 500000;i++)
    {
        begin = clock();
        _vec.push_back(i);
        end = clock();
        vec_time += end - begin;
    }

    for(int i = 0;i < 500000;i++)
    {
        begin = clock();
        _list.push_back(i);
        end = clock();
        list_time += end - begin;
    }

    for(int i = 0;i < 500000;i++)
    {
        begin = clock();
        _deq.push_back(i);
        end = clock();
        deq_time += end - begin;
    }

    cout << "vector back insert:" << vec_time << endl;
    cout << "list back insert:" << list_time << endl;
    cout << "deque back insert:" << deq_time << endl;

    return 0;
}