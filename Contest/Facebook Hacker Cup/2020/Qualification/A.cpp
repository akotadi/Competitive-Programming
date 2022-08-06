#include <bits/stdc++.h>

#define forn(i,a) for(int i = 0; i < a; i++)
#define endl '\n'

using namespace std;

int cmod(int n, int mod){
	return ( ( ( (n) % (mod) ) + (mod) ) % (mod) );
}

void solve(int t){
	int n;
	cin >> n;

	string in, out;
	cin >> in >> out;

	vector< vector<bool> > ans(n, vector<bool>(n, false));

	forn(i, n){
		ans[i][i] = true;
		for(int j = i; j < n-1; j++){
			if(out[j] == 'N' || in[j+1] == 'N')
				break;
			ans[i][j+1] = true;
		}
		for(int j = i; j > 0; j--){
			if(out[j] == 'N' || in[j-1] == 'N')
				break;
			ans[i][j-1] = true;
		}
	}

	cout << "Case #" << t+1 << ": " << endl;
	for(const auto &r : ans){
		for(const auto &c : r)
			cout << (c == true ? 'Y' : 'N');
		cout << endl;
	}
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	forn(i,t) 
		solve(i);
}
