#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL mod =1e9+7;
LL dp[1000005];
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    LL x,n;cin>>x>>n;
    LL coins[x];
    for(int i=0;i<x;i++)cin>>coins[i];
    dp[0]=1;
    for(LL i=1;i<=n;i++){
        dp[i]=0;
        for(auto j:coins){
            if(i-j>=0LL){dp[i]+=(dp[i-j]%mod);
            dp[i]%=mod;}
        }
        dp[i]%=mod;
    }
    cout<<dp[n]%mod<<"\n";
}