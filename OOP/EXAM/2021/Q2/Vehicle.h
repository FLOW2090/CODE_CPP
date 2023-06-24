#pragma once
#include <iostream>
using std::cout;
using std::endl;
class Vehicle{
private:
    int max_wheel_num;
    int max_wing_num;
    int wheel_num = 0;
    int wing_num = 0;
public:
    Vehicle() = default;
    ~Vehicle() = default;
    void set_max_wheel_num(int num){max_wheel_num = num;}
    void set_max_wing_num(int num){max_wing_num = num;}
    void add_wheel(){wheel_num++;}
    void add_wing(){wing_num++;}
    void run(){if(max_wing_num ==0)cout << "I am running" << endl;else cout << "I am running and flying" <<endl;}
    bool finished(){return (max_wing_num <= wing_num && max_wheel_num <= wheel_num);}
};