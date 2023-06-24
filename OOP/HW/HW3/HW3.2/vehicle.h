#pragma once
#include "engine.h"
#include "wheel.h"

class Vehicle
{
    public:
        Engine engine;
        Wheel wheel;
        string type;
        Vehicle(int num,string engine_,string type_ = "vehicle");
        void describe(void);
};