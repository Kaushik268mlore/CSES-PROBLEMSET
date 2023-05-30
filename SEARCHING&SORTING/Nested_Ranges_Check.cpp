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
struct range{
    int l,r,id;
     bool operator < (const range &other) const     //operator overloading.
    {
        if(l == other.l)
            return r > other.r;
        return l < other.l;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<range> ranges(n);
    vector<bool> contained(n);
    vector<bool> contains(n);
    for(int i = 0; i < n; i++)
    {
        cin>>ranges[i].l;
        cin>>ranges[i].r;
        ranges[i].id = i;
    }
    sort(ranges.begin(), ranges.end());
    int maxEnd = 0;
    for(int i = 0; i < n; i++)
    {
        if(ranges[i].r <= maxEnd)// if the right is less than the local maximum, it is definitely contained , as we sorted with l1<l2 and r<local max, its definitely contained
            contained[ranges[i].id] = true;
        maxEnd = max(maxEnd, ranges[i].r);
    }
    int minEnd = 1e9 + 1;
    for(int i = n-1; i >= 0; i--)
    {
        if(ranges[i].r >= minEnd)//
            contains[ranges[i].id] = true;
        minEnd = min(minEnd, ranges[i].r);
    }
    for(int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout <<"\n";
    for(int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout <<"\n";
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