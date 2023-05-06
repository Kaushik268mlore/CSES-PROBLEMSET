#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(int s,int d,int t,int n){
    if(n==0)return;
    solve(s,t,d,n-1);
    cout<<s<<" "<<t<<endl;
    solve(d,s,t,n-1);
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<((1<<n)-1)<<endl;
        solve(1,2,3,n);
    }
    return 0;
}