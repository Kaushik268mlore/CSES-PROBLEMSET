#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    /* int n;cin>>n; //this is using a hashset;
    unordered_set<int>s;
    for(int i=0;i<n;i++){int t;cin>>t;s.insert(t);}
    cout<<s.size(); */
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int cnt=0;
    sort(begin(arr),end(arr));
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1])cnt++;
    }
    cout<<cnt+1;
}