#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    for(int i=0;i<1<<n;i++){
        int num=i^(i>>1);//xor makes sure that only one bit is flipped 
        bitset<32>bs(num);
        string s=bs.to_string();
        for(int i=32-n;i<32;i++)cout<<s[i];
        cout<<endl;
    }
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