#include <vector>
#include <functional>

using std::vector;
using std::function;

template <class T>
class MyQueriable;
template<class T>
MyQueriable<T> from(const vector<T>& vec);

template <class T>
class MyQueriable
{
    private:
        vector<T> element;
    public:
        MyQueriable() = default;
        ~MyQueriable() = default;
        friend MyQueriable<T> from<>(const vector<T>& vec);
        int size(){
            return element.size();
        }
        T& operator [] (int i){
            return element[i];
        }
        MyQueriable<T>& where(function<bool(T)> f){
            vector<T> tmp;
            for(auto &x : element)
            {
                if(f(x))
                {
                    tmp.push_back(x);
                }
            }
            element = tmp;
            return *this;
        }
        MyQueriable<T>& apply(function<T(T)> f){
            for(auto &x : element)
            {
                x = f(x);
            }
            return *this;
        }
        T sum() const{
            T _sum = 0;
            for(int i = 0;i < element.size();i++)
            {
                _sum += element[i];
            }
            return _sum;
        }
};

template <class T>
MyQueriable<T> from(const vector<T>& vec)
{
    MyQueriable<T> tmp;
    tmp.element = vec;
    return tmp;
}