#include<iostream>
using namespace std;
struct drug{
    int time;
    int value;
};
int main()
{
    int T,M,dp[1001] = {0};
    drug drugs[101];
    cin >> T >> M;
    for(int i = 1;i <= M;i++)
    {
        cin >> drugs[i].time >> drugs[i].value;
    }
    for(int i = 1;i <= M;i++)
    {
        for(int j = T;j >= 0;j--)
        {
            if(j >= drugs[i].time)
                dp[j] = max(dp[j],dp[j-drugs[i].time] + drugs[i].value);
        }
    }
    cout << dp[T];
    system("pause");
    return 0;
}