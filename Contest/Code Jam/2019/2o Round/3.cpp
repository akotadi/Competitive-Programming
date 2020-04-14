#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	int index = 1;
	while(t--){
		int n;
		cin >> n;
		vector<string> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			reverse(a[i].begin(), a[i].end());
		}
		sort(a.begin(), a.end());
		for(auto& s : a) cout << s << endl;
		for(int i = 0; i < a.size() - 1; i++){
			for(int j = i + 1; j < a.size(); j++){

			}
		}
		for(auto it = a.begin(); it != a.end() - 1; it++){
			// cout << (*it) << endl;
			string aux = "";
			auto index1 = (*it).begin(), index2 = (*(it + 1)).begin();
			while(index1 != (*it).end() && index2 != (*it).end() && (*index1) == (*index2)) index1++, index2++;
			cout << *index1 << " : " << *index2 << endl;
		}
		cout << endl;
	}
	return 0;
}