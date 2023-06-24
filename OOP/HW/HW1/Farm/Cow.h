enum state_{hungry,half,full};

class Cow
{
    private:
        std::string name;
        int l;
        int u;
        int m;
    public:
        state_ state;
        std::string getname(void) const{return name;}
        int getl(void) const{return l;}
        int getu(void)const{return u;}  
        int getm(void) const{return m;}
        Cow(void){name = "NULL",l = -1;u = -1;m = -1;}
        Cow(std::string name_,int l_,int u_,int m_){name = name_;l = l_;u = u_;m = m_;}
        Cow(const Cow& cow){name = cow.name;l = cow.l;u = cow.u;m = cow.m;}
};