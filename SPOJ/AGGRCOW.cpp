#include <bits/stdc++.h>

#define MAXN 1000000005
#define forn(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)

using namespace std;

bool isPossible(vector<int> &barns, int cows, int dist){
	int cnt = 1, last = 0;
	forn(i, 1, barns.size()){
		if(barns[i] - barns[last] < dist) continue;
		cnt++;
		last = i;
	}
	return cnt >= cows;
}

void solve(){
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	sort(a.begin(), a.end());
	int left = 0, right = a.back(), mid;
	while(left+1 < right){
		mid = left + ((right - left) >> 1);
		if(isPossible(a, c, mid)) left = mid;
		else right = mid;
	}

	cout << left << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
