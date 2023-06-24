#include <vector>

using std::vector;

template <class T, int k>
class MultiDimArray
{
private:
    MultiDimArray<T, k - 1> *p;
    int size;

public:
    MultiDimArray();
    ~MultiDimArray();
    MultiDimArray(vector<T> &&vec);
    MultiDimArray<T, k - 1> *operator[](int it);
    MultiDimArray<T, k> &operator=(const MultiDimArray<T, k> &src);
    MultiDimArray<T, k> &operator=(MultiDimArray<T, k> &&src);
};

template <class T>
class MultiDimArray<T, 1>
{
private:
    T *arr;
    int size;

public:
    MultiDimArray();
    ~MultiDimArray();
    MultiDimArray(vector<T> &&_vec);
    T &operator[](int it);
    MultiDimArray<T, 1> &operator=(const MultiDimArray<T, 1> &src);
    MultiDimArray<T, 1> &operator=(MultiDimArray<T, 1> &&src);
};

template <class T, int k>
MultiDimArray<T, k>::MultiDimArray(vector<T> &&_vec) // 构造函数
{
    size = _vec[0];
    vector<T> vec = _vec;
    vec.erase(vec.begin(), vec.begin() + 1);
    p = new MultiDimArray<T, k - 1>[size];
    for (int i = 0; i < size; i++)
        p[i] = MultiDimArray<T, k - 1>(vec);
}

template <class T, int k>
MultiDimArray<T, k>::MultiDimArray() // 默认构造函数
{
    p = nullptr;
    size = 0;
}

template <class T, int k>
MultiDimArray<T, k - 1> *MultiDimArray<T, k>::operator[](int it) // 下标运算符重载
{
    return p + it;
}

template <class T, int k>
MultiDimArray<T, k>::~MultiDimArray() // 析构函数
{
    for (int i = 0; i < size; i++)
    {
        delete (p + i);
    }
}

template <class T, int k>
MultiDimArray<T, k> &MultiDimArray<T, k>::operator=(const MultiDimArray<T, k> &src) // 拷贝赋值函数
{
    size = src.size;
    p = new MultiDimArray<T, k - 1>[size];
    for (int i = 0; i < size; i++)
        p[i] = src.p[i];
    return *this;
}

template <class T, int k>
MultiDimArray<T, k> &MultiDimArray<T, k>::operator=(MultiDimArray<T, k> &&src) // 移动赋值函数
{
    p = src.p;
    src.p = nullptr;
    return *this;
}

template <class T>
MultiDimArray<T, 1>::MultiDimArray(vector<T> &&_vec) // 构造函数
{
    size = _vec[0];
    arr = new T[_vec[0]];
}

template <class T>
MultiDimArray<T, 1>::MultiDimArray() // 默认构造函数
{
    arr = nullptr;
    size = 0;
}

template <class T>
T &MultiDimArray<T, 1>::operator[](int it) // 下标运算符重载
{
    return arr[it];
}

template <class T>
MultiDimArray<T, 1>::~MultiDimArray() { delete arr; } // 析构函数

template <class T>
MultiDimArray<T, 1> &MultiDimArray<T, 1>::operator=(const MultiDimArray<T, 1> &src) // 拷贝赋值函数
{
    size = src.size;
    arr = new T[size];
    for (int i = 0; i < size; i++)
        arr[i] = src.arr[i];
    return *this;
}

template <class T>
MultiDimArray<T, 1> &MultiDimArray<T, 1>::operator=(MultiDimArray<T, 1> &&src) // 移动赋值函数
{
    arr = src.arr;
    src.arr = nullptr;
    return *this;
}
