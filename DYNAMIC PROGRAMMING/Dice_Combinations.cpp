#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL mod =1e9+7;
LL dp[1000005];
int32_t main(){
    LL n;cin>>n;
    
    dp[0]=1;
    for(LL i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=6;j++){
            if(i-j>=0LL){dp[i]+=(dp[i-j]%mod);
            dp[i]%=mod;}
        }
        dp[i]%=mod;
    }
    cout<<dp[n]%mod<<"\n";
}