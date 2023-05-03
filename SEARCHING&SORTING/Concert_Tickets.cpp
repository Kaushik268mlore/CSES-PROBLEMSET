// /*the first approach's giving me a TLE*/

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// //we'll be using a set , cuz deletion is expensive if an array is used , hence much better TC -O(logn) SC-O(n)
// int32_t main(){
//     int t=1;
//     //cin>>t;
//     while(t--){
//         int n,m;cin>>n>>m;
//         // vector<int>price(n),cust(m);
//         multiset<int>prices;
//         for(int i=0;i<n;i++){int d;cin>>d;prices.insert(-d);}
//         for(int i=0;i<m;i++){
//             // cin>>cust[i];
//             int d;cin>>d;
//             auto it=lower_bound(prices.begin(),prices.end(),-d);
//             if(it==prices.end())cout<<"-1\n";
//             else{
//                 cout<<-*(it)<<"\n";
//                 prices.erase(it);  
//             }

//         // sort(price.begin(),price.end());
//         // // for(int i=0;i<m;i++){
//         // //     if(binary_search(price.begin(),price.end(),cust[i]))cout<<cust[i]<<"\n";
//         // //     else cout<<price[lower_bound(price.begin(),price.end(),cust[i])-price.begin()]<<"\n";
//         // // }
//         // sort(cust.begin(),cust.end());
//         }
// }
// return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
// void solve(){
void solve(){
    int n,m;cin>>n>>m;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        s.insert({-x,i});
    }
    for(int i=0;i<m;i++){
        int x;cin>>x;
        auto y = s.lower_bound({-x,-1});
        if (y==s.end())cout<<-1<<"\n";
        else {
            cout<<-y->first<<"\n";
            s.erase(y);
        }
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