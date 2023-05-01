#include<bits/stdc++.h>
using namespace std;
int dp[1000005]={0};
void solve(){
    int n,x;cin>>n>>x;
    int price[n];
    int pages[n];
    for(int i=0;i<n;i++)cin>>price[i];
    for(int i=0;i<n;i++)cin>>pages[i];
    for(int i=0;i<n;i++){
        // dp[]=0;
        for(int j=x;j>=0;j--){
            if(j>=price[i])dp[j]=max(dp[j-price[i]]+pages[i],dp[j]);
        }
    }
    cout<<dp[x];
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}