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
int x,n;
cin>>x>>n;
int arr[n];
set<int>s;
s.insert(0);
s.insert(x);
map<int,int>map;// for mapping the gaps and map.back() or map.end() will return the biggest gap as the data is sorted.
// amazing problem where we use the lowerbound functions aka binary search very well...loved this problem tho
map[x]=1; //the biggest window
for(int i=0;i<n;i++){
    int v;cin>>v;
    auto it=s.lower_bound(v);
    int r=*it;
    --it;
    int l=*it;
    map[r-l]--;
    if(map[r-l]<=0)map.erase(r-l);
    s.insert(v);
    map[r-v]++;
    map[v-l]++;
    cout<<(--map.end())->first<<" ";
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