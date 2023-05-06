#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
// problem is similar to spiral square matrix , a bit observational
int exp(int x, unsigned int y){
    int res=1;
    while(y>0){
        if (y&1) res= (res*x); y=y>>1; x=(x*x);
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int c = 1;
        for (int p = 9;; n -= p, c++, p = 9*exp(10, c-1)*c) {
            if (n - p <= 0) break;
        }
        n--;
        int x = n/c;
        int y = n%c;
        int ans = exp(10, c-1) + x;
        // cerr<<ans<<' '<<x<<' '<<y<<' '<<n<<' '<<c;
        string s = to_string(ans);
        // cout<<s<<"\n";
        cout<<s[y]<<endl;
    }
}