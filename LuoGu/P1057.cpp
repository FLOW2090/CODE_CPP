#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n,m,**p;
    cin >> n >> m;
    p = new int*[m];
    for(int i = 0;i < m;i++)
    {
        p[i] = new int[n];
    }
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            p[i][j] = 0;
        }
    }
    p[0][1] = p[0][n-1] = 1;
    for(int i = 1;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(j > 0 && j < n-1){
                p[i][j] = p[i-1][j-1] + p[i-1][j+1];
            }
            else if(j == 0){
                p[i][j] = p[i-1][n-1] + p[i-1][j+1];
            }
            else{
                p[i][j] = p[i-1][j-1] + p[i-1][0];
            }
        }
    }
    cout << p[m-1][0];
    system("pause");
    return 0;
}