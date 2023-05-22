#include<iostream>
using namespace std;
int dp[10001] = {0};
int k[10001] = {0};
int m[10001] = {0};
int main()
{
    int v,n,c,sum = 0;
    cin >> v >> n >> c;
    for(int i = 0;i < n;i++){
        cin >> k[i] >> m[i];
        sum += k[i];
    }
    for(int i = 0;i < n;i++)//重复n次，每次其实是对i-1次数据的更新
    {
        for(int j = c;j >= m[i];j--)//为了达到更新的目的，要从体力大的方向开始更新，因为调用i-1次数据时只会调用比该体力值小的部分
        {
            dp[j] = max(dp[j],dp[j - m[i]] + k[i]);
        }
    }
    if(dp[c] < v)
    {
        cout << "Impossible";
    }
    else
    {
        int i = c;
        while(dp[i] >= v)
        {
            i--;
        }
        i++;
        cout << c-i;
    }
    system("pause");
    return 0;
}