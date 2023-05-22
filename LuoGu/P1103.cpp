#include<iostream>
#include<algorithm>
using namespace std;
struct book{
    int index;
    int value;
};
bool mycmp(book a,book b){return a.index < b.index;}
int main()
{
    int n,k,f[101][101] = {0};
    book books[101] = {0};
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> books[i].index >> books[i].value;
    sort(books+1,books+n+1,mycmp);
    int sum = 0;
    for(int i = 1;i <= n;i++)
    {
        f[i][0] = sum + abs(books[i].value - books[i-1].value);
    }
    for(int i = 2;i <= n;i++)
    {
        for(int j = 1;j < i;j++)
        {
            f[i][j] = 1000007;
            for(int k = 1;k < i;k++)
            {
                if(j-i+k-1 >= 0 && f[k][j-i+k-1]> 0)f[i][j] = min(f[i][j],f[k][j-i+k-1] + abs(books[i].value - books[k].value));
            }
        }
    }
    int ans = 1000007;
    for(int i = 1;i <= n;i++)
    {
        if(i-n+k >= 0 && f[i][i-n+k] && f[i][i-n+k] < ans) ans = f[i][i-n+k];
    }
    cout << ans;
    system("pause");
    return 0;
}