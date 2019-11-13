#include <bits/stdc++.h>

#define SIZE 262150
#define MAXN 262150
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int n;
unordered_multiset<int> check;
unordered_map<int, int> values;
vector<int> a, result;

int main(){
	cin >> n;
	int sz = pow(2, n);
	a.resize(sz);
	rep(i,sz){ 
		cin >> a[i];
		values[a[i]]++;
	}	
	sort(a.begin(), a.end());
	if(n == 1){
		cout << ((a[0] == 0)?(to_string(a[1])):("impossible")) << endl;
		return 0;
	}
	check.insert(0);
	if(values.find(0) == values.end()){
		cout << "impossible" << endl;
		return 0;
	}
	values[0]--;
	result.push_back(a[1]);
	values[a[1]]--;
	check.insert(a[1]);
	result.push_back(a[2]);
	values[a[2]]--;
	check.insert(a[2]);
	if(values.find(a[1] + a[2]) == values.end() || values[a[1] + a[2]] == 0){
		cout << "impossible" << endl;
		return 0;
	}
	values[a[1]+a[2]]--;
	check.insert(a[1]+a[2]);
	for(int i = 3; i < sz; i++){
		if(values[a[i]] == 0) continue;
		if(result.size() == n){
			cout << "impossible" << endl;
			return 0;
		}else
			result.push_back(a[i]);
		auto aux = check;
		for(const auto& num : aux){		
			if(values.find(a[i] + num) == values.end() || values[a[i] + num] == 0){
				cout << "impossible" << endl;
				return 0;
			}
			values[a[i] + num]--;
			check.insert(a[i] + num);
		}
	}

	for(const auto &num : result)
		cout << num << endl;

	return 0;
}
