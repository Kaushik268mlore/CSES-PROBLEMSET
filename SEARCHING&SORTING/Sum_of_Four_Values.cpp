#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>os;
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
    vector<vector<int>>arr(n,vector<int>(2,0));
    // unordered_map<int,int>m;
    for(int i=0;i<n;i++){cin>>arr[i][0];arr[i][1]=i;}
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
        int curr=arr[i][0]+arr[j][0];
        int l=j+1,r=n-1;
        while(l<r){
            int currsum=arr[l][0]+arr[r][0];
            if(currsum==x-curr){cout<<arr[i][1]+1<<" "<<arr[j][1]+1<<" "<<arr[l][1]+1<<" "<<arr[r][1]+1;return;}
            else if(currsum>x-curr)r--;
            else l++;
        }
    }
}
    cout<<"IMPOSSIBLE\n";
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1;
    // cin>>t;
    while(tc--){
        solve();
    }
    return 0;
}