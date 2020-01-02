#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector< pair<int,int> > a(n);
	int aux;
	for(int i = 0; i < n; i++){
		cin >> aux;
		a[i] = {aux, i};
	}
	sort(a.begin(), a.end());
	cout << 1;
	int left = a.front().se, right = a.front().se;
	for(int i = 1; i < n; i++){
		left = min(left, a[i].se);
		right = max(right, a[i].se);
		if(right - left > i)
			cout << 0;
		else
			cout << 1;
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
