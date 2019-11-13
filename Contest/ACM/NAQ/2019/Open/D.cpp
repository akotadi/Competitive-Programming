#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	unordered_set<int> check;
	int maxN = -1;
	while(n--){
		int aux;
		cin >> aux;
		maxN = aux;
		check.insert(aux);
	}
	bool flag = true;
	for(auto i{1}; i <= maxN; i++){
		if(check.find(i) == check.end()){
			flag = false;
			cout << i << endl;
		}
	}
	if(flag)
		cout << "good job" << endl;
	return 0;
}
