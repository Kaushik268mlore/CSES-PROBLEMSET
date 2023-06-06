#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define ll long long 
// class ST{ //segment tree
//     vector<ll>seg;
//  public:
//     ST(ll n){
//         seg.resize(4*n+1);
//     }
//     void build(ll ind,ll low,ll high,vector<ll>arr){
//         if(low==high){
//             seg[ind]=arr[low];
//             return;
//         }
//         ll mid=(low+high)>>1;
//         build(2*ind+1,low,mid,arr);
//         build(2*ind+2,mid+1,high,arr);
//         seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
//     }
//     ll query(ll ind,ll low,ll high,ll l,ll r){
//             // there are 3 cases of 
//             //when the range is not overlapping
//             if(r<low||high<l)return ll_MAX;
//             // when the range  is completely inside the query
//             if(low>=l&&high<=r)return seg[ind];
//             // when the query is partially overlapping
//             ll mid=(low+high)>>1;
//             ll left=query (2*ind+1,low,mid,l,r);
//             ll right=query(2*ind+2,mid+1,high,l,r);
//             return min(left,right); 
//     }
//     void update(ll ind,ll low,ll high , ll i,ll val){
//         if(low==high){
//             seg[ind]=val;
//         }
//         ll mid=(low+high)>>1;
//         if(i<=mid)update(2*ind+1,low,mid,i,val);//left
//         else update(2*ind+2,mid+1,high,i,val);//right
//         seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);//updation of the rest of the nodes.
//     }
// };
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>os;
// struct custom_hash {
//     static ull64_t splitmix64(ull64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(ull64_t x) const {
//         static const ull64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
ll n,k;
vector<ll>arr;
bool check(ll s){
    ll cnt=1,acc=0;
    for(ll i=0;i<n;i++){
        if(arr[i]>s)return false;
        else if(arr[i]+acc>s){cnt++;acc=arr[i];}
        else acc+=arr[i];
    }
    if(cnt<=k)return true;
    return false;
}
void solve(){
    cin>>n>>k;
    arr.assign(n,0);
    for(ll i=0;i<n;i++)cin>>arr[i];
    if(k>n){cout<<0;return;}
    ll  r=accumulate(arr.begin(),arr.end(),0);
    ll l=1;
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
