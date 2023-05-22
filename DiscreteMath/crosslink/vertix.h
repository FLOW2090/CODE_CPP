#pragma once
class Vertix
{
    private:
        int data;
        int* pin;//第一条入边
        int* pout;//第一条出边
    public:
        Vertix();
        Vertix(int data_,int* pin_ = nullptr,int* pout_ = nullptr);
        //~Vertix();
};