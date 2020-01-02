#include <bits/stdc++.h>

using namespace std;

string s;

void solve(){
	cin >> s;
	int n = s.size();
	for(int i = 1; i < n; i++) 
		if(s[i] != '?' && s[i] == s[i-1]){
			cout << -1 << endl;
			return;
		}
	if(s[0] == '?'){
		if(n > 1)
			s[0] = (s[1] == 'a')?('b'):('a');
		else
			s[0] = 'a';
	}
	if(s[n-1] == '?'){
		if(n > 1)
			s[n-1] = (s[n-2] == 'a')?('b'):('a');
		else
			s[n-1] = 'a';
	}
	for(int i = 1; i < n-1; i++){
		if(s[i] == '?'){
			if(s[i+1] == '?' || s[i-1] == s[i+1]){
				s[i] = (s[i-1] == 'a')?('b'):('a');
			}else if(s[i-1] == 'a'){	
				s[i] = (s[i+1] == 'c')?('b'):('c');
			}else if(s[i-1] == 'b'){	
				s[i] = (s[i+1] == 'a')?('c'):('a');
			}else{
				s[i] = (s[i+1] == 'b')?('a'):('b');
			}


		}
	}
	cout << s << endl;
}

int main(){
	int t;
	cin >> t;
	string s;
	while(t--) solve();
	return 0;
}
