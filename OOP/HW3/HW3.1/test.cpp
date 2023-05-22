#include<iostream>
using namespace std;


class Appearance {
    int weight = 0;
public:
    Appearance(){cout << '1';}
    Appearance(int _w):weight(_w){cout << '1';}
    ~Appearance(){}
};

class Small{
protected:
    Appearance A;
};

class Animal {
protected:
    Appearance A;
public:
    Animal(){} // (1)
    Animal(int _w){A = Appearance(_w);} // (2)
    ~Animal(){}
};

class Rabbit: public Animal { // (3)
    Animal N{1};
public:
    Rabbit(){}
    Appearance getA() {return A;}
    ~Rabbit(){}
};

int main() {
    Rabbit R;
    return 0;
}
