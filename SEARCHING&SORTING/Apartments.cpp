#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,m,k;cin>>n>>m>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>b(m);
    for(int i=0;i<m;i++)cin>>b[i];
    sort(arr.begin(),arr.end());
    sort(b.begin(),b.end());
    int cnt=0,l=0,v=0;
    while(l<n&&v<m){
        if(abs(arr[l]-b[v])<=k&&b[v]!=-1){cnt++;l++;v++;}
        else if(arr[l]<b[v])l++;
        else v++;
    }
    cout<<cnt;
}