#include <iostream>
#include <vector>
#include <algorithm>
namespace haha{
    void func(){;}
};

namespace huhu{
    void func(){;}
};

using std::vector;
using std::cout;
using namespace haha;
using namespace huhu;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 1, 2, 3, 4};
    auto begin = vec.begin();
    auto end = vec.end();
    cout << *begin << ' ' << *end; // (1)
    auto b = find(vec.begin(), vec.end(), 3);

    vec.erase(b + 1);         // (2)
    vec.erase(vec.end() - 4); // (3)

    cout << *end; // (4)

    return 0;
}