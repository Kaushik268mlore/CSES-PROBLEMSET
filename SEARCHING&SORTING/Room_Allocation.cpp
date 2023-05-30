#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
// #define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>os;
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
    vector<vector<int>>arr(n,vector<int>(3,0));//s,e,actual index.
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
        arr[i][2]=i;
    }
    sort(arr.begin(),arr.end());
    int res[n];
    // set<pair<int,int>>s;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(pq.size()==0){
            pq.push({arr[i][1],cnt});
            res[arr[i][2]]=cnt++;
            // cnt++;
        }
        else {
            auto v=pq.top();
            if(v[0]<arr[i][0]){
                pq.pop();
                res[arr[i][2]]=v[1];
                pq.push({arr[i][1],v[1]});
            }
            else{
                // cnt++;
                pq.push({arr[i][1],cnt});
                res[arr[i][2]]=cnt++;
            }
        }
        
    }
    cout<<cnt-1<<"\n";
    for(int i:res)cout<<i<<" ";
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
// 1 1 2 1 1 2 3 2 1 3