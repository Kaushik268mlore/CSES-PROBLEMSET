#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        if(i==1)cout<<0<<endl;
        else if(i==2)cout<<6<<endl;
        else{
        int tot=i*i;
        int tot_avail=tot*(tot-1)/2,res;
        if(i>2){
            res=tot_avail-(4*(i-1)*(i-2));
        }
        cout<<res<<"\n";}
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