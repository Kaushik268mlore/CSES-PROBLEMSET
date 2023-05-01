#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int vis[n+1];
    int cnt=0;
    if(n<=3&&n>1){cout<<"NO SOLUTION\n";return;}
    else if(n==1){cout<<1; return;}
    else{
        for(int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
    }
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