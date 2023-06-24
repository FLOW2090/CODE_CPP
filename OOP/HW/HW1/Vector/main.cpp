#include <iostream>
#include "Vector.h"

int main() {
    Vector v1(1.1, 1.2, 1.3);
    Vector v2(0, -3.4, 2.5);
    Vector v3 = v1 + v2;
    std::cout << v3 << std::endl;
    Vector v4 = v3 + 2;
    Vector v5 = 3 * v4 + 5;
    std::cout << v5 << std::endl;
    Vector v6 = 1.4 - (3 * v2 - v1);
    std::cout << v6 << std::endl;
    return 0;
}
