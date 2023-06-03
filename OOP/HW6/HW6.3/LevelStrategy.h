#pragma once

class LevelStrategy
{
    public:
        LevelStrategy() = default;
        ~LevelStrategy() = default;
        virtual int getLevel() = 0;
};

class P1LStrategy : public LevelStrategy
{
    public:
        int getLevel() override {return 2000;}
};

class P2LStrategy : public LevelStrategy
{
    public:
        int getLevel() override {return 5000;}
};

class P3LStrategy : public LevelStrategy
{
    public:
        int getLevel() override {return 10000;}
};