#include<bits/stdc++.h> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ln '\n'
typedef long long ll;

// class ST{ //segment tree
//     vector<int>seg;
//  public:
//     ST(int n){
//         seg.resize(4*n+1);
//     }
//     void build(int ind,int low,int high,vector<int>arr){
//         if(low==high){
//             seg[ind]=arr[low];
//             return;
//         }
//         int mid=(low+high)>>1;
//         build(2*ind+1,low,mid,arr);
//         build(2*ind+2,mid+1,high,arr);
//         seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
//     }
//     int query(int ind,int low,int high,int l,int r){
//             // there are 3 cases of 
//             //when the range is not overlapping
//             if(r<low||high<l)return INT_MAX;
//             // when the range  is completely inside the query
//             if(low>=l&&high<=r)return seg[ind];
//             // when the query is partially overlapping
//             int mid=(low+high)>>1;
//             int left=query (2*ind+1,low,mid,l,r);
//             int right=query(2*ind+2,mid+1,high,l,r);
//             return min(left,right); 
//     }
//     void update(int ind,int low,int high , int i,int val){
//         if(low==high){
//             seg[ind]=val;
//         }
//         int mid=(low+high)>>1;
//         if(i<=mid)update(2*ind+1,low,mid,i,val);//left
//         else update(2*ind+2,mid+1,high,i,val);//right
//         seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);//updation of the rest of the nodes.
//     }
// };
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>os;
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
// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int> values(n);
//     for(int i = 0; i < n; i++)
//         cin >> values[i];
//     ordered_set< pair<int,int> > window;
//     for(int i = 0; i < k; i++)
//         window.insert({values[i],i});
//     int med=window.find_by_order((k-1)/2)->first ;
//     // cout<<accumulate(arr.begin(),arr.end(),)
//     int cost=0;
//     for(int i=0;i<k;i++){cost+=abs(med-values[i]);}
    
//     cout<<cost<<" ";
    
//     for(int i = 1; i < n-k+1; i++)
//     {
//         window.erase({values[i-1],i-1});
//         window.insert({values[i+k-1],i+k-1});
//         cost=0;
//         int med=window.find_by_order((k-1)/2)->first ;
//         for(int j=i;j<i+k;j++){cost+=abs(med-values[j]);}
//         cout<<cost<<" ";
//     }
// }
// above approach didnt work, instead will have to use another approach
void solve(){
	int n,k;
	cin >> n >> k;
	set<pair<int,int>> leftSet;
	set<pair<int,int>> rightSet;
	vector<int> values(n);
    for(int i = 0; i < n; i++)
        cin>>values[i];
	if (k == 1)
	{
        for(int i = 0; i < n; i++)
			cout << 0 << " ";
		return;
	}
	if (k == 2)
	{
        for(int i = 1; i < n; i++)
			cout << abs(values[i-1]-values[i]) << " ";
		return;
	}
	vector<pair<int,int>> st;
    for(int i = 0; i < k; i++)
		st.push_back({values[i],i});
	sort(st.begin(),st.end());
    ll leftSetSum = 0;
    ll rightSetSum = 0;
    for(int i = 0; i < k/2 + (k%2); i++)
    {
		leftSet.insert(st[i]);
        leftSetSum += st[i].first;
    }
    for(int i = k/2 + (k%2); i < k; i++)
    {
		rightSet.insert(st[i]);
        rightSetSum += st[i].first;
    }
	ll median = leftSet.rbegin()->first;
	cout << median * leftSet.size() - leftSetSum
        + rightSetSum - median * rightSet.size() << " ";
    for(int j = 1; j < n-k+1; j++)
	{
		if (leftSet.count({values[j-1],j-1}))
        {
            leftSetSum -= values[j-1];
			leftSet.erase({values[j-1],j-1});
        }
		else
        {
            rightSetSum -= values[j-1];
			rightSet.erase({values[j-1],j-1});		
        }
		if (*(leftSet.rbegin()) < make_pair(values[k-1+j],k-1+j))
        {
            rightSetSum += values[k-1+j];
			rightSet.insert({values[k-1+j],k-1+j});
        }
		else
        {
            leftSetSum += values[k-1+j];
			leftSet.insert({values[k-1+j],k-1+j});
        }
		while (leftSet.size() < k/2+(k%2))
		{
			pair<int,int> z = (*rightSet.begin());
			leftSet.insert(z);
            leftSetSum += z.first;
			rightSet.erase(z);
            rightSetSum -= z.first;
		}
		while (leftSet.size() > k/2+(k%2))
		{
			pair<int,int> z = (*leftSet.rbegin());
			leftSet.erase(z);
            leftSetSum -= z.first;
			rightSet.insert(z);
            rightSetSum += z.first;
		}
		median = leftSet.rbegin()->first;
	    cout << median * leftSet.size() - leftSetSum
            + rightSetSum - median * rightSet.size() << " ";
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