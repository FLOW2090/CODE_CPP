#include "motor.h"

Motor::Motor(int num,string engine_) : Vehicle::Vehicle(num,engine_,"motor"){}
void Motor::describe(void)
{
    cout << "A motor with " << wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << endl;
}
void Motor::sell(void)
{
    cout << "A motor is sold!" << endl;
}