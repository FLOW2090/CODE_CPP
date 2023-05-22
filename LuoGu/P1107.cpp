#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int main()
{
    int N,H,Delta;
    cin >> N >> H >> Delta;
    int **fruit = new int*[H];
    int **ans = new int*[H];
    int *pre = new int[H];

    for(int i = 0;i < H;i++)
    {
        fruit[i] = new int[N];
        ans[i] = new int[N];
        pre[i] = 0;
    }
    for(int i = 0;i < H;i++)
    {
        for(int j = 0;j < N;j++){
            fruit[i][j] = 0;
            ans[i][j] = 0;
        }
    }

    for(int i = 0;i < N;i++)
    {
        int temp;
        cin >> temp;
        for(int j = 0;j < temp;j++)
        {
            int tem;
            cin >> tem;
            fruit[tem-1][i]++;
        }
    }

    for(int i = 0;i < N;i++)
    {
        ans[H-1][i] = fruit[H-1][i];
    }

    for(int i = H-2;i >= 0;i--)
    {
        for(int j = 0;j < N;j++)
        {
            if(i + Delta < H)
            {
                ans[i][j] = max(ans[i][j],pre[i+Delta] + fruit[i][j]);
            }
            ans[i][j] = max(ans[i][j],ans[i+1][j] + fruit[i][j]);
            pre[i] = max(pre[i],ans[i][j]);
        }
    }

    int maximum = 0;
    for(int i = 0;i < N;i++){
        maximum = max(maximum,ans[0][i]);
    }
    cout << maximum;
    system("pause");
    return 0;
}