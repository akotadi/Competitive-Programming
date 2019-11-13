#include <bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)
#define fi first
#define se second

using namespace std;

int main(){
	int n;
	cin >> n;
	vector< pair<int, int> > a(n);
	int x;
	rep(i,n){
		cin >> x;
		a[i] = {x,i};
	}
	sort(a.begin(), a.end());
	for(int i = 0, j = n-1; i < j; i++, j--)
		swap(a[i].fi, a[j].fi);
	sort(a.begin(), a.end(), [](pair<int, int> &a, pair<int, int> &b){return a.se < b.se;});
	rep(i, n){
		cout << a[i].fi;
		if(i != n-1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}
