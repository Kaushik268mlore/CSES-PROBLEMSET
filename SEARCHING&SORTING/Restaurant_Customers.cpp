#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n;cin>>n;
    vector<int>arr(n),b(n);
    for(int i=0;i<n;i++)cin>>arr[i]>>b[i];
    sort(arr.begin(),arr.end());
    sort(b.begin(),b.end());
    int mx=0;
    int c=0, x=0,y=0;
    while(x<n){
        if (arr[x]<b[y]){c++;x++;}
        else {c--;y++;}
        mx = max(mx,c);
    }
    cout<<mx;
}