#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
// cool fastexponetiation problem
int expo(int a,int b,int mod){
    int res=1;
    a%=mod;
    if(a==0)return 0;
    while(b>0){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
} 
void solve(){
    int n,y;cin>>n>>y;
    cout<<expo(2,n,mod)<<"\n";
    // cout<<expo(2,y,mod)<<"\n";
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