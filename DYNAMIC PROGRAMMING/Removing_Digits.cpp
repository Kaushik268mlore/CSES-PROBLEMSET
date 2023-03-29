#include<bits/stdc++.h>
using namespace std;
// int solve(int i,vector<int>&dp){// my recursive solution is giving me TLE.
//     if(i==0)return i;
//     if(dp[i]!=-1)return dp[i];
//     int n=i;
//     int ans=INT_MAX;
//     while(n){
//     int digit=n%10;
//     if(!digit)continue;
//     ans=min(ans,solve(i-digit,dp)+1);
//     n/=10;
//     }
//     return dp[i]=ans;
// }
int32_t main(){
    int n;cin>>n;
    // unordered_set<char>s(n.begin(),n.end());
    // vector<int>dp(n+1,-1);
      vector<int> dp(n+1,1e9);
  dp[0] = 0;
  for (int i = 0; i <= n; i++) {
    for (char c : to_string(i)) {
      dp[i] = min(dp[i], dp[i-(c-'0')]+1);
    }
  }
  cout << dp[n] << endl;
}