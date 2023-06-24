class Farm
{
    private:
        int size;
        Cow* cows;
        int* food;
        double milk;
    public:
        Farm(int n){size = n;cows = new Cow[n];food = new int[n];for(int i = 0;i < n;i++) food[i] = 0;milk = 0;}
        void addCow(Cow cow)
        {
            static int cnt = 0;
            cows[cnt++] = cow;
        }
        void supply(std::string name_,int a)
        {
            for(int i = 0;i < size;i++)
            {
                if(cows[i].getname() == name_)
                {
                    food[i] += a;
                }
            }
        }
        void startMeal(void)
        {
            for(int i = 0;i < size;i++)
            {
                if(food[i] >= cows[i].getl())
                {
                    if(food[i] > cows[i].getu()) food[i] -= cows[i].getu();
                    else food[i] = 0;
                    cows[i].state = full;
                }
                else if(food[i] > 0){cows[i].state = half;food[i] = 0;}
                else {cows[i].state = hungry;food[i] = 0;}
            }
        }
        void produceMilk(void)
        {
            for(int i = 0;i < size;i++)
            {
                switch(cows[i].state)
                {
                    case full:
                        milk += cows[i].getm();
                        break;
                    case half:
                        milk += ((double)cows[i].getm() / 2);
                        break;
                    default:
                        break;
                }
            }
        }
        double getMilkProduction(void){return milk;}
};