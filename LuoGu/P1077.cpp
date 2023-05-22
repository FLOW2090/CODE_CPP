#include<iostream>
#define mod 1000007
using namespace std;
int main()
{
    int m,n,a[101] = {0},dp[101] = {0};
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dp[0] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = m;j >= 0;j--)
        {
            for(int k = 1;k <= a[i] && k <= j;k++)
            {
                dp[j] = (dp[j] + dp[j-k]) % mod;
            }
        }
    }
    cout << dp[m];
    system("pause");
    return 0;
}