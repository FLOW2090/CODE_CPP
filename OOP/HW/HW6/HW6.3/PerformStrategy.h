#pragma once

class PerformStrategy
{
    protected:
        double perform;
    public:
        PerformStrategy() = default;
        ~PerformStrategy() = default;
        virtual double calPerform(int salary) = 0;
};

class sPerformStrategy : public PerformStrategy
{
    public:
        sPerformStrategy(double _perform){perform = _perform;}
        double calPerform(int salary) override {return salary + 1000.0;}
};

class mPerformStrategy : public PerformStrategy
{
    public:
        mPerformStrategy(double _perform){perform = _perform;}
        double calPerform(int salary) override {return double(salary) + double(salary) * perform;}
};

class lPerformStrategy : public PerformStrategy
{
    public:
        lPerformStrategy(double _perform){perform = _perform;}
        double calPerform(int salary) override {return double(salary) + double(salary) * perform + double(salary) * perform;}
};