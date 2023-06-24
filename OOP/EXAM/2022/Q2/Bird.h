#include "Animal.h"

class Bird : public Animal
{
    public:
        Bird(int c) : Animal(c){};
        ~Bird() override{
            switch (_color)
            {
                case blue:
                    cout << "Blue bird is gone." << endl;
                    break;
                case red:
                    cout << "Red bird is gone." << endl;
                    break;
                default:
                    break;
            }
        }
        void sing() override{
            switch (_color)
            {
                case blue:
                    cout << "Blue bird is singing." << endl;
                    break;
                case red:
                    cout << "Red bird is singing." << endl;
                    break;
                default:
                    break;
            }
        }
        void swim() override{cout << "Bird can not swim." << endl;}
};