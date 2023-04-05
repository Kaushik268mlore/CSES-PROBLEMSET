#include <bits/stdc++.h>
using namespace std;
// a simple 2 pointers solution
int32_t main(){
    int t=1;
    //cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int cnt=0;
        int l=0,r=n-1;
        int curr=0;
        while(l<r){
            if(arr[l]+arr[r]<=x)l++,r--;
            else r--;
            cnt++;
        }
        if(l==r)cnt++;
        cout<<cnt<<"\n";
    }
    return 0;
}