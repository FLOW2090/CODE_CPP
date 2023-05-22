#include<iostream>
using namespace std;
int main()
{
    int n,f[19][19] = {0};
    cin >> n;
    for(int i = 0;i < 19;i++)
    {
        f[0][i] = 1;
    }
    for(int i = 1;i < 19;i++)
    {
        for(int j = 0;j < 19;j++)
        {
            if(j)
            {
                f[i][j] = f[i-1][j+1]+f[i][j-1];
            }
            else
            {
                f[i][j] = f[i-1][j+1];
            }
        }
    }
    cout << f[n][0];
    system("pause");
    return 0;
}