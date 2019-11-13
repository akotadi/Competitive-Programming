#include <bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)
#define fi first
#define se second
#define pb push_back
#define prec(n,a) fixed << setprecision(n) << a

using namespace std;

typedef long long int lli;

int main(){
	int n;
	cin >> n;
	vector< pair<lli, lli> > a;
	lli x, y;
       	lli maxA = -1;
	rep(i,n){
		cin >> x >> y;
		maxA = max(maxA, x * y);
		a.pb({min(x,y), max(x,y)});
	}
	
	sort(a.begin(), a.end(), [](pair<lli, lli> &a1, pair<lli, lli> &a2){
			return (a1.fi == a2.fi) ? a1.se < a2.se : a1.fi > a2.fi;
			});
	if(n == 1){
		long double res = maxA;
		res /= 2;
		cout << prec(1,res) << endl;
		return 0;
	}
	lli ans = -1;
	set<lli> check;
	check.insert(a[0].se);
	forn(i,1,n){
		auto aux = check.lower_bound(a[i].se);
		if(aux == check.end()){
			aux--;
			ans = max(ans, a[i].fi * (*aux));
		}else
			ans = max(ans, a[i].fi * a[i].se);
		check.insert(a[i].se);
	}
	
	if(ans * 2 < maxA){
		long double res = maxA;
		res /= 2;
		cout << prec(1,res) << endl;
	}else
		cout << prec(1,(long double)ans) << endl;

	return 0;
}
