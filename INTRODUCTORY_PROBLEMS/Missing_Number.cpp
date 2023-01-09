#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum=n*(n+1)/2;
    int rem=0;
    for(int x:arr){
        rem+=x;
    }
    cout<<sum-rem;
}