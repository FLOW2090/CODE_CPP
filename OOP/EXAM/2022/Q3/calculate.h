template <class T>
T calculate(char type,int _x,int _y,int _z)
{
    T x = T(_x),y = T(_y),z = T(_z);
    switch(type)
    {
        case 'A':
            return x*x+y*y+z*z;
            break;
        case 'B':
            return x*y+y/z-x*z;
            break;
        case 'C':
            return y*3*z-x*z/(y-2)-x*y/(z+1);
            break;
        default:
            break;
    }
}