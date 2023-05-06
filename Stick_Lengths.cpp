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
vector<int>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];
sort(arr.begin(),arr.end());
int m1,m2,s1=0,s2=0;
if(n&1){
    m1=arr[n/2];
    for(int i:arr){s1+=abs(i-m1);}
    cout<<s1<<"\n";
}
else {
    m1=arr[n/2];
    m2=arr[(n/2)+1];
    for(int i:arr){
        s1+=abs(i-m1);
        s2+=abs(i-m2);
    }
    cout<<min(s1,s2);
}
// int res=0;

// cout<<res;
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