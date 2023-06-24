#pragma once
#include <functional>
using namespace std;

class Click {
private:
    function<void()> ClickCommand;
    // TODO
public:
    // TODO
    Click() = default;
    // TODO
    void setClickCommand(std::function<void()> f){ClickCommand = f;}
    // TODO
    virtual void click(){ClickCommand();}
};
class DoubleClick {
private:
    function<void()> DoubleClickCommand;
    // TODO
public:
    // TODO
    DoubleClick() = default;
    // TODO
    void setDoubleClickCommand(std::function<void()> f){DoubleClickCommand = f;}
    // TODO
    virtual void doubleClick(){DoubleClickCommand();}
};