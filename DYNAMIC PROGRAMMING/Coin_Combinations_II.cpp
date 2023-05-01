// #include<bits/stdc++.h>
// using namespace std;
// #define LL long long
// LL mod =1e9+7;
// LL dp[1000005];
// int32_t main(){
//     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//     LL x,n;cin>>x>>n;
//     LL coins[x];
//     for(int i=0;i<x;i++)cin>>coins[i];
//     sort(coins,coins+x);
//     dp[0]=1;
//     for(int j=0;j<x;j++){
//         // dp[i]=0;
//         for(LL i=1;i<=n;i++){
//             if(i-coins[j]>=0LL){dp[i]+=(dp[i-coins[j]]%mod);
//             dp[i]%=mod;}
//         }
//         // dp[i]%=mod;
//     }
//     cout<<dp[n]%mod<<"\n";
// }
#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int dp[1000005]={0};
void solve(){
	int n,x; see(n,x);
	vi v; seev(v,n);
	sort(all(v));
	dp[0]=1;
	rep(i,0,n){
		rep(j,1,x+1){
			if (j-v[i]>=0)dp[j]+= dp[j-v[i]];
			dp[j]%=md;
		}
	}
	put(dp[x]);
}	
signed main(){
	IOS;
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
    	solve();
    	//cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}