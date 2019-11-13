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
#define pb push_back

#define MAXN 400010

using namespace std;

typedef long long int lli;

void solve(){
	int n, k, m;
	cin >> n >> k >> m;
	string s;
	vector< bitset<50> > a, b;
	vector< vector<int> > save(n, vector<int>(n, -1));
	rep(i,n){
		cin >> s;
		bitset<50> x(s);
		reverse(s.begin(), s.end());
		bitset<50> y(s);
		a.pb(x);
		b.pb(y);
	}
	int res = 100;
	rep(i,n){
		int count = 0;
		bool flag = true;
		rep(j,n){
			if(i == j) continue;
			auto aux = a[i] ^ a[j];
			int num = aux.count();
			if(num > m){
				aux = a[i] ^ b[j];
				num = aux.count();
				count++;
			}
			if(num > m){
				flag = false;
				break;
			}
		}
		if(flag) res = min(res, count);
		count = 1;
		flag = true;
		rep(j,n){
			if(i == j) continue;
			auto aux = b[i] ^ a[j];
			int num = aux.count();
			if(num > m){
				aux = b[i] ^ b[j];
				num = aux.count();
				count++;
			}
			if(num > m){
				flag = false;
				break;
			}
		}
		if(flag) res = min(res, count);
	}
	cout << res << endl;
}

int main(){
	int t; 
	cin >> t;
	while(t--) solve();
	return 0;
}
