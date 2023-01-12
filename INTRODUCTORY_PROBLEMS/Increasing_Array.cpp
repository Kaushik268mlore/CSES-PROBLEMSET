#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    vector<int>arr(n);
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m=arr[0];
    for(int i=1;i<n;i++){
        ans+=max(0LL,m-arr[i]);     
        m=max(m,arr[i]);
    }
    cout<<ans;
}