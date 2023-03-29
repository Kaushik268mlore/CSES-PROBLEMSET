#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,t;cin>>n>>t;
    vector<int>c(n);
    vector<int>dp(t+1);
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=1;i<=t;i++){
        dp[i]=INT_MAX;
        for(auto j: c){
            if(i-j>=0){
                dp[i]=min(dp[i-j]+1,dp[i]);
            }
        }
    }
    if(dp[t]<INT_MAX)cout<<dp[t];
    else cout<<-1;
}
int32_t main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}