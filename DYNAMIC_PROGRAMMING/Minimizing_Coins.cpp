#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int32_t main(){
     int n,x;
     cin>>n>>x;
     int arr[n];
     for(int i=0;i<n;i++)cin>>arr[i];
     
     for(int i=1;i<=x;i++){
        dp[i]=10000006;
        for(int coin:arr){
            if(i-coin>=0)dp[i]=min(dp[i-coin]+1,dp[i]);
        }
     }
     if(dp[x]<10000006)cout<<dp[x];
     else cout<<-1;
}