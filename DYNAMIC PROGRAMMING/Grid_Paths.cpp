#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];
void solve(){
    int mod=1e9+7;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                char c;cin>>c;
                if(c=='*')dp[i][j]=0;
                else if(i==1&&j==1)dp[i][j]=1;
                else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n][n];
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