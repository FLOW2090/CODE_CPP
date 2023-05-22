#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[100000],dp[100000],f[100000],maxlen = 1,n = 0;;
    while(n < 8)
    {
        scanf("%d",&arr[n++]);
    }
    n--;
    f[1] = arr[0];
    for(int i = 1;i < n;i++)
    {
        if(arr[i] <= f[maxlen])
        {
            f[++maxlen] = arr[i];
        }
        else{
            int left = 1,right = maxlen;
            while(left < right)
            {
                int mid = (left + right) / 2;
                if(arr[i] <= f[mid]) left = mid;
                else right = mid;
            }
            f[right++] = arr[i];
        }
    }
    printf("%d",maxlen);
    system("pause");
    return 0;
}