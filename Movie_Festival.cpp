#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;
    });
    int cnt=1;
    int prev=arr[0].second;
    for(int i=1;i<n;i++){
        if(arr[i].first>=prev){cnt++;prev=arr[i].second;}
    }
    cout<<cnt<<"\n";
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