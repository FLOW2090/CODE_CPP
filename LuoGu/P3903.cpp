#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<cstring>
#include<math.h>

using namespace std;

int main(){
    int n,*arr,**dp,max = 1;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int) * n);
    dp = (int**)malloc(sizeof(int*) * n);
    for(int i = 0;i < n;i++) dp[i] = (int*)malloc(sizeof(int) * n);
    for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
    for(int i = 0;i < n;i++) dp[i][1] = 1;
    for(int i = 1;i < n;i++){
        for(int j = i - 1;j >= 0;j--){
            if(arr[i] > arr[j]){
                if(dp[j][0] + 1 > dp[i][1]) dp[i][1] = dp[j][0] + 1;
            }
            if(arr[i] < arr[j]){
                if(dp[j][1] + 1 > dp[i][0]) dp[i][0] = dp[j][1] + 1;
            }
            if(dp[i][0] > max) max = dp[i][0];
            if(dp[i][1] > max) max = dp[i][1];
        }
    }
    printf("%d",max);
    system("pause");
    return 0;
}