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
    vector<int> _vec(10000000);
    list<int> _list(10000000);
    deque<int> _deq(10000000);
    clock_t begin, end, vec_time, list_time, deq_time;

    begin = clock();
    for(auto it : _vec){}
    end = clock();
    vec_time = end - begin;

    begin = clock();
    for(auto it : _list){}
    end = clock();
    list_time = end - begin;

    begin = clock();
    for(auto it : _deq){}
    end = clock();
    deq_time = end - begin;

    cout << "vector ergodic:" << vec_time << endl;
    cout << "list ergodic:" << list_time << endl;
    cout << "deque ergodic:" << deq_time << endl;

    return 0;
}