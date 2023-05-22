#include "chef.h"
#include<vector>
class Manager
{
    private:
        int size;
        std::vector<Chef> chefs;

    public:
        Manager(void);
        void newChef(Chef);
        void order(std::string dish,int chefId = -1);
};