#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>os;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// void solve(){ Okay so using pbds for the josephus1 will give TLE, instead I'll have to use math lol
//     int n;cin>>n;
//     // int arr[n+1];
//     os s;
//     for(int i=1;i<=n;i++)s.insert(i);
//     int i=2;
//     while(n--){
//             auto y=s.find_by_order(i);
//             cout<<*y<<" ";
//             s.erase(y);
//             if(n>0){
//                 i=(i+2)%n;}
//     }
// }
// you can always use queue . add 1 to n elements in a queue. 
// just pop the first element and add it to the queue again. 
// Now the second element, or now the first element in the queue, push it in the vector and pop. 
// continue till you have 1 element left in the queue. 
// Also push the last element, print the vector
void solve(){
    int n;cin>>n;
    int inc=0,mul=1;
    // while(n--){
    queue<int>q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    vector<int>res;
    while(q.size()>=2){
        int t=q.front();
        q.pop();
        int u=q.front();
        res.push_back(u);
        q.pop();
        q.push(t);
    }
    int t=q.front();
    res.push_back(t);
    // res.pop_back();
    for(int i:res)cout<<i<<" ";
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
