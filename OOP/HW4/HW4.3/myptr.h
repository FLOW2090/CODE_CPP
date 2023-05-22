#include <iostream>
using std::cout;
using std::endl;

template <class T>
class my_ptr
{
    private:
        T* ptr;
        static T* bin;
    public:
        my_ptr()
        {
            ptr = bin;
            cout << "my_ptr constructed." << endl;
        }
        my_ptr(T* tmp)
        {
            ptr = tmp;
            cout << "my_ptr constructed." << endl;
        }
        my_ptr(const my_ptr& tmp)
        {
            ptr = bin;
            cout << "Copying of my_ptr is forbidden!" << endl;
            cout << "my_ptr constructed." << endl;
        }
        my_ptr& operator = (const my_ptr& tmp)
        {
            cout << "Copying of my_ptr is forbidden!" << endl;
            cout << "my_ptr updated." << endl;
            return *this;
        }
        my_ptr(my_ptr&& tmp)
        {
            ptr = tmp.ptr;
            tmp.ptr = bin;
            cout << "my_ptr constructed." << endl;
        }
        my_ptr& operator = (my_ptr&& tmp)
        {
            if(ptr != bin)delete ptr;
            ptr = tmp.ptr;
            tmp.ptr = bin;
            cout << "my_ptr updated." << endl;
            return *this;
        }
        ~my_ptr()
        {
            if(ptr != bin)delete ptr;
            cout << "my_ptr destructed." << endl;
        }
        T& operator * ()
        {
            if(ptr == bin)
            {
                cout << "Do not attempt to read a nullptr!" << endl;
                return *bin;
            }
            return *ptr;
        }
        T* operator -> ()
        {
            if(ptr == bin)
            {
                cout << "Do not attempt to read a nullptr!" << endl;
                return bin;
            }
            return ptr;
        }
};

template<class T>
T *my_ptr<T>::bin = new T;