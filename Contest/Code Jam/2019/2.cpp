#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	int index = 1;
	while(t--){
		int n;
		string s, result = "";
		cin >> n >> s;
		bool flagOut = (s.back() == 'E')?true:false, flagIn = (s.front() == 'E')?true:false;
		if (flagOut && flagIn)
		{
			int aux = 0;
			for(int i = 0; i < s.size(); ++i) {
				if(s[i] == 'S') {
					aux++;
					if(s[i] == s[i+1]) break;
				}
			}
			for (int i = 0; i < aux; ++i) result+= 'S';
			for (int i = 0; i < n-1; ++i) result+= 'E';
			for (int i = aux; i < n-1; ++i) result += 'S';
		} else if (flagOut && !flagIn)
		{
			for (int i = 0; i < n-1; ++i) result+= 'E';
			for (int i = 0; i < n-1; ++i) result += 'S';
		} else if (!flagOut && flagIn)
		{
			for (int i = 0; i < n-1; ++i) result+= 'S';
			for (int i = 0; i < n-1; ++i) result += 'E';
		} else {
			int aux = 0;
			for(int i = 0; i < s.size(); ++i) {
				if(s[i] == 'E') {
					aux++;
					if(s[i] == s[i+1]) break;
				}
			}
			for (int i = 0; i < aux; ++i) result+= 'E';
			for (int i = 0; i < n-1; ++i) result+= 'S';
			for (int i = aux; i < n-1; ++i) result += 'E';
		}
		
		cout << "Case #" << index++ << ": " << result << endl;
	}
	return 0;
}