#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

const int INF=1e9;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	vector<array<int,2>> a(n);
	vector<array<int,3>> b(n);
	vector<array<int,3>> c(n);
	vector<int> yidx(n);
	for (int i=0;i<n;++i) {
		cin>>a[i][0]>>a[i][1];
		b[i][0]=a[i][0];b[i][1]=-a[i][1];b[i][2]=i;
		c[i][0]=a[i][1];c[i][1]=-a[i][0];c[i][2]=i;
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for (int i=0;i<n;++i) yidx[b[i][2]]=i;

	ordered_set s;
	fill(a.begin(),a.end(),array<int,2>({0,0}));
	for (int i=0;i<n;++i){
		int idx=c[i][2];
		int cur=yidx[idx];
		int nless=s.order_of_key(cur);
		int nbig=s.size()-nless;
		a[idx][0]=nbig;
		a[idx][1]=cur-nless;
		s.insert(cur);
	}
	for (int i=0; i<n; ++i){
		if (i!=0) cout<<' ';
		cout<<a[i][0];
	}
	cout<<'\n';

	for (int i=0; i<n; ++i){
		if (i!=0) cout<<' ';
		cout<<a[i][1];
	}
	cout<<'\n';
	return 0;
}