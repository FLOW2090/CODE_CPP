#include "PerformStrategy.h"
#include "LevelStrategy.h"

class Calculator
{
    private:
        LevelStrategy* levelStrategy;
        PerformStrategy* performStrategy;
    public:
        Calculator(LevelStrategy* m_levelStrategy,PerformStrategy* m_performStrategy) : levelStrategy(m_levelStrategy), performStrategy(m_performStrategy){}
        int get_base(){return levelStrategy->getLevel();}
        int get_total(int base){return performStrategy->calPerform(base);}
};