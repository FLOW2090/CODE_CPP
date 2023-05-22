#include "car.h"

Car::Car(int num,string engine_) : Vehicle::Vehicle(num,engine_,"car"){}
void Car::describe(void)
{
    cout << "A car with " << wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << endl;
}