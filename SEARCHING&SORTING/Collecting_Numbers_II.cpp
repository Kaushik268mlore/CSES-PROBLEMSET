#include<bits/stdc++.h>
using namespace std;
#define int long long
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
void solve(){
int n,m;cin>>n>>m;
unordered_map<int,int>map;
int arr[n+1];
for(int i=1;i<=n;i++){
    int t;cin>>t;
    map[t]=i;
    arr[i]=t;
}
int c=1;
    for(int i=1;i<n;i++){
        if(map[i]>map[i+1])c++;
    }
// for(int i=0;i<m;i++){        //this loop is giving me TLE.. so some kmap of optimisation has to be done
//     int a,b;cin>>a>>b;
//     swap(map[arr[a]],map[arr[b]]);
//     swap(arr[a],arr[b]);
//     int c=1;
//     for(int i=1;i<n;i++){
//         if(map[i]>map[i+1])c++;
//     }
//     // swap(map[arr[a]],map[arr[b]]);
//     // swap(arr[a],arr[b]);
//     cout<<c<<"\n";
// }
while(m--){
    int x,y; cin>>x>>y;
		int r = arr[x], s = arr[y];
		swap(arr[x], arr[y]);
        // these cases handle both i-1 & i + i & i+1  for both < and > cases so each index 4 cases , in total 8 cases
        // honestly a great optimisation does in O(1) and overall complexity still remains O(n); 
		if (map[r-1] <= map[r] && map[r-1] > y) c++;
		if (map[r-1] > map[r] && map[r-1] <= y) c--;
		if (map[r] <= map[r+1] && y > map[r+1]) c++;
		if (map[r] > map[r+1] && y <= map[r+1]) c--;		
		map[r] = y;
		if (map[s-1] <= map[s] && map[s-1] > x) c++;
		if (map[s-1] > map[s] && map[s-1] <= x) c--;
		if (map[s] <= map[s+1] && x > map[s+1]) c++;
		if (map[s] > map[s+1] && x <= map[s+1]) c--;	
		map[s] = x;
		cout<<c<<endl;
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