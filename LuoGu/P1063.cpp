#include<iostream>
using namespace std;
int main()
{
    int n,arr[1000] = {0},f[300][300] = {0};
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)//从第i行开始的矩形区域
    {
        for(int j = 1;j < n;j++)//偏移量j
        {
            for(int k = i;k <= i + n - 1;k++)//对行进行dp
            {
                for(int r = 0;r + 1 <= j;r++)
                {
                    if(j + 1 <= n)f[k][k+j] = max(f[k][k+j],f[k][k+r] + f[k+r+1][k+j] + arr[k] * arr[k+r+1] * arr[k+j+1]);
                    else f[k][k+j] = max(f[k][k+j],f[k][k+r] + f[k+r+1][k+j] + arr[k] * arr[k+r+1] * arr[k]);
                }
            }
        }
        if(f[i][i+n-1] > ans) ans = f[i][i+n-1];
    }
    cout << ans;
    system("pause");
    return 0;
}