#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
int n,m;cin>>n>>m;
if(min(n,m)*2>=max(n,m)&&(n+m)%3==0)cout<<"YES\n";
else cout<<"NO\n";
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}