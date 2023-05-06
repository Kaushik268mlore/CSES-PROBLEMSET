#include<bits/stdc++.h>
using namespace std;
// #define int long long
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
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int cnt=0,res=1;
    // unordered_set<int>s; kinda giving me TLE.
    // s.insert(arr[0]);
    // for(int i=1;i<n;i++){
    //     if(arr[i-1]!=arr[i]&&s.count(arr[i])==0){s.insert(arr[i]);
    //     int l=s.size();
    //     res=max(res,l);
    //     }
    //     else {
    //         s.clear();
    //         s.insert(arr[i]);
    //     }
    // }
    unordered_map<int,int,custom_hash>mp;// sliding window solution...
    for(int i=0,j=0;i<n;i++){
        while(j<n&&mp[arr[j]]<1){
            mp[arr[j]]++;
            j++;
        }
        res=max(res,j-i);
        mp[arr[i]]--;//clearing the rear end of the window..
    }
    cout<<res;
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