#include<bits/stdc++.h>
using namespace std;
#define int long long
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
    int n;cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){int val;cin>>val;
    auto it=upper_bound(arr.begin(),arr.end(),val);
    if(it==arr.end())arr.push_back(val);
    else arr[it-arr.begin()]=val;
    }
    // stack<int>
    // int top=arr[0];
    cout<<arr.size();
    
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