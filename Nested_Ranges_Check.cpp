#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>os;
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
void solve(){
    int n;cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        arr[i]=make_pair(a,b);
    }
    vector<int>res1(n);
    vector<int>res2(n);
    sort(arr.begin(),arr.end(),[&](pair<int,int>&a,pair<int,int>&b){
        return ()
    })
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