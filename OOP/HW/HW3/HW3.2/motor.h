#include "vehicle.h"

class Motor : public Vehicle
{
    public:
        Motor(int num,string engine_);
        void describe(void);
        void sell(void);
};