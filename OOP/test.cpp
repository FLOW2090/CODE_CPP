#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {0,1,2,3,4};
    std::move(arr);
    int b = arr[2];
    return 0;
}