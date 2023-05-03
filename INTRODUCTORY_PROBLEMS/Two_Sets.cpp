#include<bits/stdc++.h>
using namespace std;
#define int long long
//not done yet, fell asleep :p
void solve(){
    int n;cin>>n;
    int sum=n*(n+1)/2;
    vector<int>v1,v2;
    if(sum%2==0){
        if(n%4==0){
            cout<<"YES\n";
            for(int i=1;i<=n;i++){
                if(i%4==1||i%4==0)v1.push_back(i);
                else v2.push_back(i);
            }
			cout<<v1.size()<<"\n";
			for(auto i:v1)cout<<i<<" ";
			cout<<"\n";
			cout<<v2.size()<<"\n";
			for(auto i:v2)cout<<i<<" ";
			cout<<"\n";
        }
        else if(n%4==3){
			cout<<"YES\n";
			for(int i=1;i<n;i++){
				if(i%4==1||i%4==2)v1.push_back(i);
				else v2.push_back(i);
			}
			v2.push_back(n);
			cout<<v1.size()<<"\n";
			for(auto i:v1)cout<<i<<" ";
			cout<<"\n";
			cout<<v2.size()<<"\n";
			for(auto i:v2)cout<<i<<" ";
			cout<<"\n";
		}

    }
    else cout<<"NO\n";
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