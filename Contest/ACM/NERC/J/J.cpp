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

bool isPossible(vector<lli> &a, lli g, lli r){
	lli res = 0, last = 0;
	for(const auto &it : a){
		res += (it + last) / g;
		if(last == 0 || last + it < g)
			last = it % g;
		else
			last = (it + last) % g;
	}

	return res >= r;
}

void solve(){
	lli n, k;
	cin >> n >> k;
	vector<lli> a(n);
	lli total = 0;
	rep(i,n) cin >> a[i], total += a[i];
	lli left = 0, right = (total / k) + 1, mid;
	while(left+1 < right){
		mid = left + ((right - left) >> 1);
		if(isPossible(a, mid, k)) left = mid;
		else right = mid;
	}

	cout << left*k << endl;
}

int main(){
	int t; 
	cin >> t;
	while(t--) solve();
	return 0;
}
