#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
// class ST{ //segment tree
//     vector<int>seg;
//  public:
//     ST(int n){
//         seg.resize(4*n+1);
//     }
//     void build(int ind,int low,int high,vector<int>arr){
//         if(low==high){
//             seg[ind]=arr[low];
//             return;
//         }
//         int mid=(low+high)>>1;
//         build(2*ind+1,low,mid,arr);
//         build(2*ind+2,mid+1,high,arr);
//         seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
//     }
//     int query(int ind,int low,int high,int l,int r){
//             // there are 3 cases of 
//             //when the range is not overlapping
//             if(r<low||high<l)return INT_MAX;
//             // when the range  is completely inside the query
//             if(low>=l&&high<=r)return seg[ind];
//             // when the query is partially overlapping
//             int mid=(low+high)>>1;
//             int left=query (2*ind+1,low,mid,l,r);
//             int right=query(2*ind+2,mid+1,high,l,r);
//             return min(left,right); 
//     }
//     void update(int ind,int low,int high , int i,int val){
//         if(low==high){
//             seg[ind]=val;
//         }
//         int mid=(low+high)>>1;
//         if(i<=mid)update(2*ind+1,low,mid,i,val);//left
//         else update(2*ind+2,mid+1,high,i,val);//right
//         seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);//updation of the rest of the nodes.
//     }
// };
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
// void solve(){        // this is straight off a dumb approach to do this , but it is brute force.
//     int n,k;cin>>n>>k;
//     vector<int>arr(n);
//     unordered_map<int,int>m;
//     for(int i=0;i<n;i++){cin>>arr[i];m[arr[i]]++;}
//     // unordered_set<int>s(arr.begin(),arr.end());
//     // int un=s.size();
//     // // if(un<=)
//     // cout<<m.size()<<endl;
//     // if(mp.size())
//     int cnt=0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             unordered_set<int>s(arr.begin()+i,arr.begin()+j);
//             for(int i:s)cout<<i<<" ";
//             cout<<"\n";
//             if(s.size()<=k)cnt++;
//         }
//     }
//     cout<<cnt;
// }
void solve(){
    int n,k;cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int res=0;
        unordered_map<int,int>map;
        for(int i=0,j=0;i<arr.size();++i){
             if(!map[arr[i]]++){k--;}
             while(k<0){
              if(!--map[arr[j]]){k++;}
              j++;
            }
            res+=i-j+1;
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