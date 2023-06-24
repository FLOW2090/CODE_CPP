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

    vector<int>::iterator it;

    for(int i = 0;i < 500000;i++)
    {
        it = _vec.begin();
        begin = clock();
        _vec.insert(it,i);
        end = clock();
        vec_time += end - begin;
    }

    for(int i = 0;i < 500000;i++)
    {
        begin = clock();
        _list.push_front(i);
        end = clock();
        list_time += end - begin;
    }

    for(int i = 0;i < 500000;i++)
    {
        begin = clock();
        _deq.push_front(i);
        end = clock();
        deq_time += end - begin;
    }

    cout << "vector front insert:" << vec_time << endl;
    cout << "list front insert:" << list_time << endl;
    cout << "deque front insert:" << deq_time << endl;

    return 0;
}