#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n), res(n+1);
	for(auto &it : a) cin >> it;
	unordered_set<int> check;
	for(int i = n-1; i >= 0; i--){
		check.insert(a[i]);
		res[i+1] = check.size();
	}
	int l;
	for(int i = 0; i < m; i++){
		cin >> l;
		cout << res[l] << endl;
	}
	return 0;
}
