#include <bits/stdc++.h>

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}

#define forn(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)
#define fi first
#define se second

#define MAXN 400010

using namespace std;

typedef long long int lli;

bool isPossible(vector<lli> a, lli g, lli r){
	lli res = 0, last = 0;
	if(a[0] < g) a[1] -= g - a[0];
	if(a[2] < g) a[1] -= g - a[2];

	return a[1] > 0;
}

void solve(){
	lli n = 3, k = 3;
	vector<lli> a(n);
	lli total = 0;
	rep(i,3) cin >> a[i], total += a[i];
	if(a[0] > a[2]) swap(a[0], a[2]);
	lli left = 0, right = (total / k) + 1, mid;
	while(left+1 < right){
		mid = left + ((right - left) >> 1);
		if(isPossible(a, mid, k)) left = mid;
		else right = mid;
	}

	cout << left << endl;
}

int main(){
	int t; 
	cin >> t;
	while(t--) solve();
	return 0;
}
