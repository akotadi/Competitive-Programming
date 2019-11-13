#include <bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)

using namespace std;

int n, k, g1, g2, g3, r;
string s;
vector< vector<int> > dp;

int main(){
	cin >> n >> k >> g1 >> g2 >> g3 >> s;
	for(const auto &c : s) if(c == '#') r++;
	dp.resize(n+1, vector<int>(r+1, -1));
	return 0;
}
