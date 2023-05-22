#include"vertix.h"

Vertix::Vertix(int data_,int* pin_ = nullptr,int* pout_ = nullptr)
{
    data = data_;
    pin = pin_;
    pout = pout_;
}

Vertix::Vertix()
{
    data = -1;
    pin = nullptr;
    pout = nullptr;
}