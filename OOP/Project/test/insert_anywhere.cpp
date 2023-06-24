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
    srand((unsigned)time(NULL));
    vector<int> _vec;
    list<int> _list;
    deque<int> _deq;
    clock_t begin, end, vec_time = 0, list_time = 0, deq_time = 0;
    int tmp;
    vector<int>::iterator vec_it;
    list<int>::iterator list_it;
    deque<int>::iterator deq_it;

    for(int i = 0;i < 100000;i++)
    {
        tmp = (double)rand() / (RAND_MAX + 1) * (_vec.size());
        vec_it = tmp + _vec.begin();
        begin = clock();
        _vec.insert(vec_it,i);
        end = clock();
        vec_time += end - begin;
    }

    for(int i = 0;i < 100000;i++)
    {
        tmp = (double)rand() / (RAND_MAX + 1) * (_list.size());
        list_it = find(_list.begin(),_list.end(),tmp);
        begin = clock();
        _list.insert(list_it,i);
        end = clock();
        list_time += end - begin;
    }

    for(int i = 0;i < 100000;i++)
    {
        tmp = (double)rand() / (RAND_MAX + 1) * (_deq.size());
        deq_it = tmp + _deq.begin();
        begin = clock();
        _deq.insert(deq_it,i);
        end = clock();
        deq_time += end - begin;
    }

    cout << "vector insert anywhere:" << vec_time << endl;
    cout << "list insert anywhere:" << list_time << endl;
    cout << "deque insert anywhere:" << deq_time << endl;

    return 0;
}