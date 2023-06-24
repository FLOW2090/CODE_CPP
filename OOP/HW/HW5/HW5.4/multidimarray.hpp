#pragma once
#include <vector>
using std::vector;

template <typename T,int Dim>
class MultiDimArray{
private:
    int _size;
    vector<MultiDimArray<T,Dim-1>> data;
public:
    MultiDimArray(vector<int> init){
        _size = init[init.size() - Dim];
        for(int i = 0;i < _size;i++)
        {
            data.push_back(MultiDimArray<T,Dim-1>(init));
        }
    }
    MultiDimArray(const MultiDimArray<T,Dim>& other) : _size(other._size),data(other.data){};
    ~MultiDimArray() = default;
    MultiDimArray<T,Dim>& operator = (const MultiDimArray<T,Dim>& other)
    {
        if(this == &other)
        {
            return *this;
        }
        _size = other._size;
        data = other.data;
        return *this;
    }
    MultiDimArray<T,Dim>& operator = (MultiDimArray<T,Dim>&& other)
    {
        if(this == &other)
        {
            return *this;
        }
        _size = other._size;
        data = other.data;
        return *this;
    }
    MultiDimArray<T,Dim-1>& operator [] (const int pos)
    {
        return data[pos];
    }
};

template<typename T>
class MultiDimArray<T,1>{
private:
    int _size;
    vector<T> data;
public:
    MultiDimArray(const vector<int> init) : _size(init[init.size() - 1]),data(_size){};
    ~MultiDimArray() = default;
    MultiDimArray(const MultiDimArray<T,1> &other) : _size(other._size),data(other.data){};
    MultiDimArray operator = (const MultiDimArray<T,1> &other)
    {
        _size = other._size;
        data = other.data;
        return *this;
    }
    MultiDimArray& operator = (MultiDimArray<T,1>&& other)
    {
        if(this == &other)
        {
            return *this;
        }
        _size = other._size;
        data = other.data;
        return *this;
    }
    T& operator [] (int pos)
    {
        return data[pos];
    }
};