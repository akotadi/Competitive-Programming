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

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	rep(i,m) cin >> a[i], a[i]--;
	vector< pair<int, int> > res(n);
	unordered_map<int, int> nums, pos;
	rep(i,n){ 
		nums[i] = i;
		pos[i] = i;
		res[i] = {i,i};
	}
	for(const auto &it : a){
		if(pos[it] == 0) continue;
		int prev = nums[pos[it]-1];
		res[prev].se = max(res[prev].se, pos[it]);
		res[it].fi = min(res[it].fi, pos[it]-1);
		swap(nums[pos[it]], nums[pos[it]-1]);
		pos[it]--;
		pos[prev]++;
	}
	for(const auto &p : res)
		cout << p.fi+1 << " " << p.se+1 << endl;
	return 0;
}
