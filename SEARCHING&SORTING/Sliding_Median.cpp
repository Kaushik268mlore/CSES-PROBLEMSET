//  using ordered set
// #include<bits/stdc++.h> 
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
 
// using namespace std;
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define ln '\n'
// typedef long long ll;

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<int> values(n);
//     for(int i = 0; i < n; i++)
//         cin >> values[i];
//     ordered_set< pair<int,int> > window;
//     for(int i = 0; i < k; i++)
//         window.insert({values[i],i});
//     cout << window.find_by_order((k-1)/2)->first << " ";
//     for(int i = 1; i < n-k+1; i++)
//     {
//         window.erase({values[i-1],i-1});
//         window.insert({values[i+k-1],i+k-1});
//         cout << window.find_by_order((k-1)/2)->first << " ";
//     }
// }
// using only sets and sliding window
#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
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
			cout << values[i] << " ";
		return 0;
	}
	if (k == 2)
	{
        for(int i = 1; i < n; i++)
			cout << min(values[i-1],values[i]) << " ";
		return 0;
	}
	vector<pair<int,int>> st;
    for(int i = 0; i < k; i++)
		st.push_back({values[i],i});
	sort(st.begin(),st.end());
    for(int i = 0; i < k/2 + (k%2); i++)
		leftSet.insert(st[i]);
    for(int i = k/2 + (k%2); i < k; i++)
		rightSet.insert(st[i]);
	auto t = leftSet.rbegin();
	cout << t->first << " ";
    for(int j = 1; j < n-k+1; j++)
	{
		if (leftSet.count({values[j-1],j-1}))
			leftSet.erase({values[j-1],j-1});
		else
			rightSet.erase({values[j-1],j-1});		
		if (*(leftSet.rbegin()) < make_pair(values[k-1+j],k-1+j))
			rightSet.insert({values[k-1+j],k-1+j});
		else
			leftSet.insert({values[k-1+j],k-1+j});
		while (leftSet.size() < k/2+(k%2))
		{
			pair<int,int> z = (*rightSet.begin());
			leftSet.insert(z);
			rightSet.erase(z);
		}
		while (leftSet.size() > k/2+(k%2))
		{
			pair<int,int> z = (*leftSet.rbegin());
			leftSet.erase(z);
			rightSet.insert(z);
		}
		cout << leftSet.rbegin()->first << " ";
	}	
}