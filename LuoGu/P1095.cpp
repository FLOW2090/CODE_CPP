#include<iostream>
using namespace std;
int main()
{
    int magic,dis,time,t,d;
    cin >> magic >> dis >> time;
    t = time;
    d = dis;
    while(magic >= 10)
    {
        dis -= 60;
        time--;
        magic -= 10;
        if(time == 0 || dis <= 0) break;
    }
    if(dis <= 0)
    {
        cout << "Yes" << endl << t - time;
        system("pause");
        return 0;
    }
    else if(time == 0){
        cout << "No" << endl << d - dis;
        system("pause");
        return 0;
    }
    else
    {
        while(time > 0 && dis > 0)
        {
            int need,run;
            if((10 - magic) % 4 == 0) need = (10 - magic) / 4;
            else need = (10 - magic) / 4 + 1;
            if(dis % 17 == 0) run = dis / 17;
            else run = dis / 17 + 1;
            if(need + 1 > time || run < need + 1 || dis <= 68)
            {
                time--;
                dis -= 17;
            }
            else
            {
                time -= (need + 1);
                magic = magic - 10 + need * 4;
                dis -= 60;
            }
        }
    }
    if(dis <= 0) cout << "Yes" << endl << t - time;
    else if(time == 0) cout << "No" << endl << d - dis;
    system("pause");
    return 0;
}