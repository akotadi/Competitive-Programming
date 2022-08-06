#include <bits/stdc++.h>

#define forn(i,a) for(int i = 0; i < a; i++)

using namespace std;

void solve(int t){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0;
	for(const auto& c : s){
		if(c == 'A') 
			a++;
		else
			b++;
	}
	cout << "Case #" << t << ": " << (abs(a-b) > 1 ? 'N' : 'Y') << endl;
}

int main(){
	int t;
	cin >> t;
	forn(i,t) solve(i+1);

	return 0;
}
