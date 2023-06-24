#pragma once
#include "window.h"
#include <iostream>
#include <memory>
#pragma once
#include <list>
using namespace std;

class ClearAll {
private:
    list<shared_ptr<Checkbox>> l;
    // TODO
public:
    // TODO
    ClearAll(list<shared_ptr<Checkbox>> checkbox) : l(checkbox){}
    void operator()(){
        for(auto c : l)
        {
            c.reset();
        }
    }
};

class SelectAll {
private:
    list<shared_ptr<Checkbox>> l;
    // ...
public:
    // TODO
    SelectAll(list<shared_ptr<Checkbox>> checkbox) : l(checkbox){}
    void operator()(){
        for(auto c : l)
        {
            c->isChosen = true;
        }
    }
};

class Submit {
    list<shared_ptr<Checkbox>> l;
    // ...
public:
    // TODO
    Submit(list<shared_ptr<Checkbox>> checkbox) : l(checkbox) {}
    void operator()(){
        for(auto c : l)
        {
            if(c->isChosen)
            {
                cout << c->getName() << " is selected" << endl;
            }
            else
            {
                cout << c->getName() << " is not selected" << endl;
            }
        }
    }
};