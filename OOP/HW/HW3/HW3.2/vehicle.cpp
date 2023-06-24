#include "vehicle.h"

Vehicle::Vehicle(int num,string engine_,string type_) : wheel(num),engine(engine_),type(type_)
{
    cout << "Finish building a " << type << " with " << wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << endl;
}
void Vehicle::describe(void)
{
    cout << "A vehicle with " << wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << endl;
}