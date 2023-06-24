#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>

template<class T>
class Data
{
public:
    int length;
    Data(int _length) : length(_length) {}
    virtual const T& get(int index) = 0;
};

template<class T>
class DataEmpty : public Data<T>
{
public:
    DataEmpty<T>(): Data<T>(0) {};
    const T& get override(int index) {
        assert(0); // No data in DataEmpty
    }
};

template<class T>
class DataPushBackDecorator : public Data<T>
{
public:
    Data<T>* _data;
    T _value;
    DataPushBackDecorator(Data<T>* data, T value) : _data(data), _value(value), Data(data->length + 1){}
    const T& get override(int index){
        int time = this->length - index - 1, tmp = _value;
        Data<T>* tmp_data = _data;
        for(int i = 0;i < time;i++)
        {
            tmp_data = tmp_data->_data;
            tmp = tmp_data->value;
        }
        return tmp;
    }
    // Implement a Decorator for push_back operation
};

template<class T>
class DataSetDecorator : public Data<T>
{
public:
    Data<T>* _data;
    int _index;
    T _value;
    DataSetDecorator(Data<T>* data, int index, T value) : _data(data), _index(index), _value(value), Data(data->length){}
    const T& get override(int index)
    {
        if(_index != index)
        {
            _data->get(index);
        }
        else
        {
            return _value;
        }
    }
    // Implement a Decorator for set operation
};


template<class T>
class PVector
{
public:
    Data<T>* data;
    PVector<T>() {
        data = new DataEmpty<T>();
        // when to delete??
    }
    PVector<T>(Data<T>* _data): data(_data) { }
    PVector<T> push_back(const T &value) const{
        return PVector<T>(new DataPushBackDecorator<T>(data, value));
    }
    PVector<T> set(int index, const T &value) const{
        return PVector<T>(new DataSetDecorator<T>(data, index, value));
    }

    const T& operator[](int index){
        return data->get(index);
    }
};

template<class T>
ostream& operator << (ostream& out, const PVector<T>& vec)
{
    out << '[' << vec[0];
    for(int i = 1;i < vec.length;i++)
    {
        out << ', ' << vec[i];
    }
    out << ']';
    return out;
}