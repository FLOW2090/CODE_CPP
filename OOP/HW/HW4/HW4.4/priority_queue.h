#pragma once
#include "abstract_compare.h"
#include <vector>

using std::vector;

template<class T> class PriorityQueue {
public:
    PriorityQueue(AbstractCompare<T> *_cmp){com = _cmp;}
    ~PriorityQueue(){};
    bool empty()
    {
        return queue.empty();
    }
    int size()
    {
        return queue.size();
    }
    void push(T element)
    {
        queue.push_back(element);
        int size = queue.size();
        //std::cout << size;
        for(int i = size - 1;i > 0;i--)
        {
            if(com->compare(queue[i],queue[i-1]))
            {
                T tmp = queue[i];
                queue[i] = queue[i-1];
                queue[i-1] = tmp;
            }
            else break;
        }
    }
    void pop()
    {
        queue.erase(queue.begin(),queue.begin()+1);
    }
    T top()
    {
        return queue[0];
    }
private:
    vector<T> queue;
    AbstractCompare<T> *com;
};