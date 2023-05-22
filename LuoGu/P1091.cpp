#include<iostream>
using namespace std;
int main()
{
    int n,h[101] = {0},h_reverse[101] = {0},up[101] = {0},lo[101] = {0},total[101] = {0};
    cin >> n;
    for(int i = 1;i <= 100;i++){
        up[i] = 1;
        lo[i] = 1;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> h[i];
        h_reverse[n-i+1] = h[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j < i;j++)
        {
            if(h[i] > h[j]) up[i] = max(up[i],up[j] + 1);
            if(h_reverse[i] > h_reverse[j]) lo[i] = max(lo[i],lo[j] + 1);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        total[i] = up[i] + lo[n-i+1];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(ans < total[i]) ans = total[i];
    }
    cout << n - ans + 1;
    system("pause");
    return 0;
}