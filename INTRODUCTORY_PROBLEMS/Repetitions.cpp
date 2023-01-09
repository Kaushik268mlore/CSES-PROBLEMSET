#include<bits/stdc++.h>
using namespace std;
//#define int long long
int32_t main(){
    string n;
    cin>>n;
    int i=0,j=1,res=1,ans=0;
    for(i=0;i<n.length()-1;i++){
        if(n[i]==n[i+1]){
            res++;}
        else {ans=max(ans,res);res=1;} 
    } 
    ans=max(ans,res);
    cout<<ans;
} 