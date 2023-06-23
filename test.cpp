#include <list>
#include <vector>
#include <deque>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

void RangedRandDemo( int range_min, int range_max, int n )
{
   Generate random numbers in thehalf-closed interval
   [range_min, range_max). In other words,
   range_min <= random number <range_max
   int i;
   for ( i = 0; i < n; i++ )
   {
      int u = (double)rand() / (RAND_MAX + 1) *(range_max - range_min) // RAND_MAX = 32767
            + range_min;
      printf( "  %6d\n", u);
   }
}

int main()
{
   srand( (unsigned)time( NULL ) );
   vector<int> _vec;
   list<int> _list;
   deque<int> _deq;
   clock_t vec_begin, vec_end, list_begin, list_end,
      deq_begin, deq_end;

   vec_begin = clock();
   for(int i = 0;i < 100000;i++) _vec.push_back(i);
   vec_end = clock();

   list_begin = clock();
   for(int i = 0;i < 100000;i++) _list.push_back(i);
   list_end = clock();

   deq_begin = clock();
   for(int i = 0;i < 100000;i++) _deq.push_back(i);
   deq_end = clock();

   cout << "vector back insert:" << vec_end - vec_begin << endl;
   cout << "list back insert:" << list_end - list_begin << endl;
   cout << "deque back insert:" << deq_end - deq_begin << endl;

   cout << "******************************" << endl;

   vec_begin = clock();
   for(int i = 0;i < 100000;i++) _vec.pop_back();
   vec_end = clock();

   list_begin = clock();
   for(int i = 0;i < 100000;i++) _list.pop_back();
   list_end = clock();

   deq_begin = clock();
   for(int i = 0;i < 100000;i++) _deq.pop_back();
   deq_end = clock();

   cout << "vector back pop:" << vec_end - vec_begin << endl;
   cout << "list back pop:" << list_end - list_begin << endl;
   cout << "deque back pop:" << deq_end - deq_begin << endl;

   cout << "******************************" << endl;

   vec_begin = clock();
   for(int i = 0;i < 100000;i++) _vec.insert(_vec.begin(),i);
   vec_end = clock();

   list_begin = clock();
   for(int i = 0;i < 100000;i++) _list.push_front(i);
   list_end = clock();

   deq_begin = clock();
   for(int i = 0;i < 100000;i++) _deq.push_front(i);
   deq_end = clock();

   cout << "vector front insert:" << vec_end - vec_begin << endl;
   cout << "list front insert:" << list_end - list_begin << endl;
   cout << "deque front insert:" << deq_end - deq_begin << endl;

   cout << "******************************" << endl;

   vec_begin = clock();
   for(int i = 0;i < 100000;i++) _vec.erase(_vec.begin());
   vec_end = clock();

   list_begin = clock();
   for(int i = 0;i < 100000;i++) _list.pop_front();
   list_end = clock();

   deq_begin = clock();
   for(int i = 0;i < 100000;i++) _deq.pop_front();
   deq_end = clock();

   cout << "vector front pop:" << vec_end - vec_begin << endl;
   cout << "list front pop:" << list_end - list_begin << endl;
   cout << "deque front pop:" << deq_end - deq_begin << endl;

   cout << "******************************" << endl;


   clock_t tmp_begin,tmp_end,vec_time,list_time,deq_time;
   int _tmp_;

   vec_time = clock();
   for(int i = 0;i < 100000;i++)
   {
      _tmp_ = (double)rand() / (RAND_MAX + 1) *(_vec.size());
      tmp_begin = clock();
      _vec.insert(_vec.begin() + _tmp_,i);
      tmp_end = clock();
      vec_time += tmp_end - tmp_begin;
   }

   list_time = clock();
   for(int i = 0;i < 100000;i++)
   {
      _tmp_ = (double)rand() / (RAND_MAX + 1) *(_deq.size());
      auto it = find(_list.begin(),_list.end(),_tmp_);
      tmp_begin = clock();
      _list.insert(it,i);
      tmp_end = clock();
      list_time += tmp_end - tmp_begin;
   }

   deq_begin = clock();
   deq_end = clock();
   for(int i = 0;i < 100000;i++)
   {
      _tmp_ = (double)rand() / (RAND_MAX + 1) *(_deq.size());
      tmp_begin = clock();
      _deq.insert(_deq.begin() + _tmp_,i);
      tmp_end = clock();
      deq_time += tmp_end - tmp_begin;
   }

   cout << "vector insert anywhere:" << vec_time << endl;
   cout << "list insert anywhere:" << list_time << endl;
   cout << "deque insert anywhere:" << deq_time << endl;

   cout << "******************************" << endl;

   for(int i = 0;i < 1000000;i++)
   {
      _vec.push_back(i);
      _list.push_back(i);
      _deq.push_back(i);
   }

   vec_begin = clock();
   for(auto it : _vec)
   vec_end = clock();

   list_begin = clock();
   for(auto it : _list)
   list_end = clock();

   deq_begin = clock();
   for(auto it : _list)
   deq_end = clock();

   cout << "vector ergodic:" << vec_end - vec_begin << endl;
   cout << "list ergodic:" << list_end - list_begin << endl;
   cout << "deque ergodic:" << deq_end - deq_begin << endl;

   cout << "******************************" << endl;

   return 0;
}