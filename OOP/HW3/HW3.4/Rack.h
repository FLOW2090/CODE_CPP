#include <vector>
#include <iostream>
class Rack
{
    private:
        std::vector<int> *rack = nullptr;
    public:
        Rack();
        ~Rack();
        Rack(const Rack& rack_);
        Rack(Rack&& rack_);
        Rack& operator = (const Rack& rack_);
        Rack& operator = (Rack&& rack_);

        Rack& operator += (int);
        Rack& operator += (const Rack& rack_);
        Rack operator , (const Rack& rack_);
        Rack operator , (int a);

        bool operator < (const Rack& rack_);
        bool operator > (const Rack& rack_);
        bool operator == (const Rack& rack_);

        Rack operator & (const Rack& rack_);

        int operator () (int a);

        Rack operator ~ (void);

        Rack& operator -- (void);
        Rack& operator -- (int dummy);

        friend std::ostream& operator << (std::ostream& out,const Rack& rack_);
        friend Rack operator , (int a,Rack& rack_);
};