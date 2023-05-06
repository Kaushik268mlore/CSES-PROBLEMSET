#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string s;cin>>s;
    sort(s.begin(),s.end());
    string temp=s;
    int n=s.length();
    vector<string>res;
    while(next_permutation(s.begin(),s.end()))res.push_back(s);
    cout<<res.size()+1<<"\n";
    cout<<temp<<"\n";
    for(string a:res)cout<<a<<"\n";
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