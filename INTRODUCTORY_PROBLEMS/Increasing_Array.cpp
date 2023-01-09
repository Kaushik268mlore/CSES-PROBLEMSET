#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    vector<int>arr(n);
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i>0&&arr[i]<arr[i-1])ans+=(arr[i-1]-arr[i]);
    }
    cout<<ans;
}