#pragma once
#include"vertix.h"
class Edge
{
    private:
        Vertix start;
        Vertix end;
        int info;
        Edge* elink;//指向下一个具有相同终点的边
        Edge* slink;//指向下一个具有相同起点的边
    public:
        //Edge();
        Edge(Vertix start_,Vertix end_,int info_,Edge* elink_ = nullptr,Edge* slink_ = nullptr);
        //~Edge();
};