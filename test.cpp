#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

int fun1(int a){};
int fun2(int a){};

int main(){
    function<int(int)> arr[] = {fun1,fun2};
    cout << greater<int>()(2,1);
}