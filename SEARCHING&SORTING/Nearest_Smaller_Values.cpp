#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
    int t;cin>>t;
    int ans=0;
    while(arr.size()){
        if(arr.back().first>=t)arr.pop_back();
        else if(arr.back().first<t){ ans=arr.back().second;break;}
    }
    cout<<ans<<" ";
    arr.push_back({t,i+1});
    }
    
}