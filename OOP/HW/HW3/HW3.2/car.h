#include "vehicle.h"

class Car : public Vehicle
{
    public:
        Car(int num,string engine_);
        void describe(void);
};