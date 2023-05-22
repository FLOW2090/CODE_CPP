#include<iostream>
using namespace std;
int main()
{
    int v,n,items[31],dp[20001] = {0};
    cin >> v >> n;
    for(int i = 1;i <= n;i++) cin >> items[i];
    for(int i = 1;i <= n;i++)
    {
        for(int j = v;j >= 0;j--)
        {
            if(j >= items[i]) dp[j] = max(dp[j],dp[j-items[i]] + items[i]);
        }
    }
    cout << v - dp[v];
    system("pause");
    return 0;
}