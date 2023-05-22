#include "altset.h"
Altset::Altset()
{
    gene = nullptr;
}
Altset::~Altset()
{
    delete gene;
}

Altset::Altset(const char *data, int len)
{
    gene = new std::vector<bool>{};
    for(int i = len-1;i >= 0;i--)
    {
        if(data[i] == '1') gene->push_back(true);
        else gene->push_back(false);
    }
}
Altset& Altset::operator = (const Altset &altset)
{
    gene = new std::vector<bool>{};
    if(this != &altset)
    {
        *gene = *(altset.gene);
    }
    return *this;
}
Altset& Altset::operator = (Altset &&altset)
{
    if(this != &altset)
    {
        gene = altset.gene;
        altset.gene = nullptr;
    }
    return *this;
}

void Altset::inverse(int index)
{
    (*gene)[index] = !(*gene)[index];
}
void Altset::append(int value)
{
    gene->push_back(value);
}
bool Altset::get(int index) const
{
    return (*gene)[index];
}
bool Altset::empty() const
{
    if(gene == nullptr) return true;
    return false;
}
int Altset::count() const
{
    int count = 0;
    for(int i = 0;i < gene->size();i++)
    {
        if((*gene)[i]) count++;
    }
    return count;
}