#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	int index = 1;
	while(t--){
		string s, aux = "";
		cin >> s;
		bool flag = false;
		for(auto& c : s){
			if (c == '4')
			{
				aux += '1';
				c = '3';
				flag = true;
			}
			else if (flag)
			{
				aux += '0';
			}
		}
		cout << "Case #" << index++ << ": " << s << " " << aux << endl;
	}
	return 0;
}