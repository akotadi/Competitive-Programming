#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int result = 0;
	for(auto i{1}; i < n; i+=2){
		if(s[i] == s[i-1]) {
			s[i] = (s[i] == 'a')?('b'):('a');
			result++;
		}
	}
	cout << result << "\n" << s << endl;
	return 0;
}
