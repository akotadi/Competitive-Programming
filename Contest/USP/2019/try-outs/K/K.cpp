#include <bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)

using namespace std;

typedef int64_t lli;

int main(){
	int n;
	cin >> n;
	lli a[n];
	rep(i,n) cin >> a[i];
	sort(a, a+n);
	lli result = 1;
	for(int i = 0; i < n && a[i] <= result; i++)
		result += a[i];

	cout << result << endl;

	return 0;
}
