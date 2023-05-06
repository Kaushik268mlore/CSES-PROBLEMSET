#include<bits/stdc++.h>
using namespace std;
#define int long long
// custom hash because we are getting TLE for last 2 cases
// after defining an efficient hash , it should pass
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve(){
    int n,x;cin>>n>>x;
    unordered_map<int,int,custom_hash>m;
    // int arr[n];
    for(int i=1;i<n+1;i++){
        int t;cin>>t;
        if(m.find(x-t)!=m.end()){
                cout<<i<<" "<<m[x-t]<<"\n";
                return;
        }
        // arr[i]=t;
        m[t]=i;
    }
    // int i;
    // for(i=0;i<n;i++){
        
    // }
    cout<<"IMPOSSIBLE\n";
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