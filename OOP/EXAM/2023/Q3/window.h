#pragma once
#include <memory>
#include <list>
#include "event.h"

using namespace std;

class Window;

class Widget {
    string _name;
    Window* _parent;
public:
    Widget(string name) :_name(name), _parent(nullptr) {}
    string getName() const { return _name; }
    Window* getParent() const { return _parent; }
    void setParent(Window * parent) {_parent = parent;}
    virtual ~Widget() {}
};

class Button :public Widget, public Click, public DoubleClick {
public:
    Button(string name) :Widget(name) {}
};

class Checkbox :public Widget, public Click {
public:
    bool isChosen;
    Checkbox(string name) : Widget(name), isChosen(false), Click() {}
    virtual void click() override {
        if(isChosen){isChosen = false;}
        else {isChosen = true;}
    }
    // TODO
};

class Window {

private:
    list<shared_ptr<Widget>> Widgets;
    // TODO

public:
    // TODO
    shared_ptr<Widget> getPointerByName(string name){
        for(auto _w : Widgets)
        {
            if(_w->getName() == name)
            {
                return _w;
            }
        }
    }
    // TODO
    Widget& getElementByName(string name){
        for(auto _w : Widgets){
            if(_w->getName() == name)
            {
                return *_w;
            }
        }
    }
    // TODO
    bool addElement(shared_ptr<Widget> w){
        for(auto _w : Widgets){
            if(w->getName() == _w->getName()) return false;
            if(w == _w) return false;
            if(w.get() == _w.get()) return false;
        }
        Widgets.push_back(w);
        return true;
    }
    // TODO
    bool undo(){return true;}
};
