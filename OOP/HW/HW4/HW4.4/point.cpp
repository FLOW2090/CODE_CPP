#include "point.h"

Point::Point(int _x, int _y): x(_x), y(_y) {}

Point::~Point() {}

std::istream &operator>>(std::istream &in, Point &p) {
    in >> p.x; 
    std::cout << "yes";
    in >> p.y;
    std::cout << "yes" << std::endl;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Point &p) {
    out << p.x << " " << p.y;
    return out;
}
