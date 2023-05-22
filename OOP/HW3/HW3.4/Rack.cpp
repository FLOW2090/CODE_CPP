#include "Rack.h"

Rack::Rack()
{
    rack = new std::vector<int>{};
}

Rack::~Rack()
{
    delete rack;
}

Rack::Rack(const Rack& rack_)
{
    rack = new std::vector<int>;
    *rack = *(rack_.rack);
}

Rack::Rack(Rack&& rack_)
{
    rack = rack_.rack;
    rack_.rack = nullptr;
}

Rack& Rack::operator = (const Rack& rack_)
{
    if(this != &rack_)
    {
        *rack = *(rack_.rack);
    }
    return *this;
}

Rack& Rack::operator = (Rack&& rack_)
{
    if(this != &rack_)
    {
        rack = rack_.rack;
        rack_.rack = nullptr;
    }
    return *this;
}


Rack& Rack:: operator += (int a)
{
    rack->push_back(a);
    return *this;
}

Rack& Rack::operator += (const Rack& rack_)
{
    int size = rack_.rack->size();
    for(int i = 0;i < size;i++)
    {
        rack->push_back((*(rack_.rack))[i]);
    }
    return *this;
}

Rack Rack::operator , (const Rack& rack_)
{
    Rack tmp(*this);
    int size = rack_.rack->size();
    for(int i = 0;i < size;i++)
    {
        tmp.rack->push_back((*(rack_.rack))[i]);
    }
    return tmp;
}

Rack Rack::operator , (int a)
{
    Rack tmp(*this);
    tmp.rack->push_back(a);
    return tmp;
}

bool Rack::operator < (const Rack& rack_)
{
    return (rack->size() < rack_.rack->size());
}

bool Rack::operator > (const Rack& rack_)
{
    return (rack->size() > rack_.rack->size());
}

bool Rack::operator == (const Rack& rack_)
{
    return (rack->size() == rack_.rack->size());
}

Rack Rack::operator & (const Rack& rack_)
{
    Rack tmp;
    for(int i = 0;i < rack->size();i++)
    {
        for(int j = 0;j < rack_.rack->size();j++)
        {
            if((*rack)[i] == (*(rack_.rack))[j])
            {
                bool flag = true;
                for(int k = 0;k < tmp.rack->size();k++)
                {
                    if((*rack)[i] == (*(tmp.rack))[i])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    tmp.rack->push_back((*rack)[i]);
                }
                break;
            }
        }
    }
    return tmp;
}

int Rack::operator () (int a)
{
    int count = 0;
    for(int i = 0;i < rack->size();i++)
    {
        if(a == (*rack)[i]) count++;
    }
    return count;
}

Rack Rack::operator ~ (void)
{
    int size = rack->size();
    int *p = new int[size];
    for(int i = 0;i < size;i++)
    {
        p[i] = (*rack)[size - i - 1];
    }
    for(int i = 0;i < size;i++)
    {
        (*rack)[i] = p[i];
    }
    return *this;
}

Rack& Rack::operator -- (void)
{
    rack->erase(rack->begin());
    return *this;
}

Rack& Rack::operator -- (int dummy)
{
    rack->pop_back();
    return *this;
}

std::ostream& operator << (std::ostream& out,const Rack& rack_)
{
    for(int i = 0;i < rack_.rack->size();i++)
    {
        out << " " << (*(rack_.rack))[i];
    }
    return out;
}

Rack operator , (int a,Rack& rack_)
{
    Rack tmp(rack_);
    tmp.rack->insert(tmp.rack->begin(),a);
    return tmp;
}