#include <bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef int64_t lli;

int main(){
	int n;
	cin >> n;
	vector< pair<int,int> > a(n);
	lli result = numeric_limits<lli>::min(), maxD = 0;
	int x, y;
	rep(i,n){
		cin >> x >> y;
		a[i] = {y, x};
	}
	sort(a.begin(), a.end());
	rep(i,n){
		result = max(result, maxD + a[i].se - a[i].fi);
		maxD += a[i].se;
	}
	
	cout << result << endl;

	return 0;
}
