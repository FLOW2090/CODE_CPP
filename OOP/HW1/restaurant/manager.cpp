#include "manager.h"

Manager::Manager(void)
{
    size = 0;
}

void Manager::newChef(Chef chef)
{
    chefs.push_back(chef);
    size++;
}

void Manager::order(std::string dish,int chefId)
{
    if(chefId == -1)
    {
        bool flag = false;
        int tmp;
        for(int i = 0;i < size;i++)
        {
            if(chefs[i].isSignatureDish(dish))
            {
                flag = true;
                tmp = i;
                break;
            }
        }
        if(flag)
        {
            chefs[tmp].cook(dish);
        }
        else chefs[0].cook(dish);
    }
    else
    {
        chefs[chefId].cook(dish);
    }
}