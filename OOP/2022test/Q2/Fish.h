#include "Animal.h"

class Fish : public Animal
{
    public:
        Fish(int c) : Animal(c){};
        ~Fish() override{
            switch (_color)
            {
                case blue:
                    cout << "Blue fish is gone." << endl;
                    break;
                case red:
                    cout << "Red fish is gone." << endl;
                    break;
                default:
                    break;
            }
        }
        void swim() override{
            switch (_color)
            {
                case blue:
                    cout << "Blue fish is swimming." << endl;
                    break;
                case red:
                    cout << "Red fish is swimming." << endl;
                    break;
                default:
                    break;
            }
        }
        void sing() override{cout << "Fish can not sing." << endl;}
};