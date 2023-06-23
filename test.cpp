#include <list>
#include <vector>
#include <deque>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

int main()
{
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

   vec_begin = clock();
   for(int i = 0;i < 100000;i++) _vec.insert(_vec.begin() + _vec.size() / 2,i);
   vec_end = clock();

   clock_t tmp_begin,tmp_end;
   list_begin = clock();
   list_end = clock();
   for(int i = 0;i < 100000;i++)
   {
      list<int>::iterator it = find(_list.begin(),_list.end(),int(i/2));
      tmp_begin = clock();
      _list.insert(it,i);
      tmp_end = clock();
      list_end += tmp_end - tmp_begin;
   }

   deq_begin = clock();
   for(int i = 0;i < 100000;i++) _deq.insert(_deq.begin() + _deq.size() / 2,i);
   deq_end = clock();

   cout << "vector insert anywhere:" << vec_end - vec_begin << endl;
   cout << "list insert anywhere:" << list_end - list_begin << endl;
   cout << "deque insert anywhere:" << deq_end - deq_begin << endl;

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