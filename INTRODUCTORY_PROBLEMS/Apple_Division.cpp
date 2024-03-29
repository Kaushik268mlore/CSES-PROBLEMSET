#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>arr(n);
    int s=0;
    // for(int i:arr){cin>>i;s+=i;}
    for(int i=0;i<n;i++){cin>>arr[i];s+=arr[i];}
    // cout<<s;
    // int l=0,r=n;
    // sort(arr.begin(),arr.end());
    //really cool way to check all permutations ,
    // i goes from 0 to 2^n -1 
    // and in bit representation , the set bits represent the index we consider for the sum
    // so in the next loop we check for the indices that are set in one of the above combinations while(j=0 to n)we see
    // which of the bits are set and if its set we add it to the cs.
    int res=0;
    for(int i=0;i<1<<n;++i){
        int cs=0;
        for(int j=0;j<n;++j){
            if(i&(1<<j))cs+=arr[j];
        }
        // cout<<"current sum"<<cs<<"\n";
        if(cs<=s/2)res=max(res,cs);
        // cout<<res<<"\n";
    }
cout<<s-2*res<<'\n';
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