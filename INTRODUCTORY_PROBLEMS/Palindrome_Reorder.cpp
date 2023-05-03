#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
string s;cin>>s;
int n=s.length();
string res="";
vector<int>arr(26);
map<char,int>m;
for(char c:s)m[c]++;
int of=0;
char c='.';
for(auto i:m){
    if(i.second&1){of++;c=i.first;}
}
if(of>1)cout<<"NO SOLUTION\n";
else{
    for(auto i:m){
        if(i.first==c)continue;
        for(int j=0;j<i.second/2;j++)res+=i.first;
    }
    if(c!='.')for(int i=0;i<m[c];i++)res+=c;
    // for(auto i:m){ // holy shit totally forgot this would print the first half again , we need to reverse it 
    //     if(i.first==c)continue;
    //     for(int j=0;j<i.second/2;j++)res+=i.first;
    // }

    for(auto i=m.rbegin();i!=m.rend();i++){
            if((*i).first==c)continue;
            for(int j=0;j<(*i).second/2;j++)res+=(*i).first;
    }
}
cout<<res;

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