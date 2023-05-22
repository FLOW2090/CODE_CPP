#include"edge.h"

Edge::Edge(Vertix start_,Vertix end_,int info_,Edge* elink_ = nullptr,Edge* slink_ = nullptr)
{
    start = start_;
    end = end_;
    info = info_;
    elink = elink_;
    slink = slink_;
}