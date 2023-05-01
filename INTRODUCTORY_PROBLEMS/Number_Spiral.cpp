#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int x,y;cin>>x>>y;
    if(x>y){
        if(x%2==0)cout<<(x*x)-y+1;
        else cout<<(x-1)*(x-1)+y;
    }
    else {
        if(y%2==0)cout<<(y-1)*(y-1)+x;
        else cout<<(y*y)-x+1;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
            solve();
            cout<<"\n";
    }
    return 0;
}