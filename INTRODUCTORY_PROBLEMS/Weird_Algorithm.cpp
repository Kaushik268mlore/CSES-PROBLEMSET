#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    cout<<n<<" ";
    while (n!=1)
    {
        if(n&1){n*=3;n+=1;cout<<n<<" ";}
        else {n/=2;cout<<n<<" ";}
    }
    
}