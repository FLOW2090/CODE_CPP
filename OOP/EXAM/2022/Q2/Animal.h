#pragma once
#include <iostream>

using std::cout;
using std::endl;

#define red 0
#define blue 1

class Animal
{
    protected:
        int _color;
    public:
        Animal() = default;
        Animal(int color) : _color(color){}
        virtual ~Animal() = 0;
        virtual void sing() = 0;
        virtual void swim() = 0;
};

Animal::~Animal(){}