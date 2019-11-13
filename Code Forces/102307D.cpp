#include<bits/stdc++.h>

#define endl '\n'
using namespace std;
string str;
int q;
int i, a, k, c;
struct query {
	int i, a, k, c, it, ak;
};
int main() {
	cin >> str;
	cin >> q;
	map<pair<int, int>, vector<query>> v;
	for (int it = 0; it < q; it++) {
		cin >> i >> a >> k >> c;
		v[{i%a, a}].push_back({i, a, k, c, it, ak});
	}

	vector<pair<int, int> >  vec(str.size());
	for (auto &i : v) {
		for (auto &h : i) {
			vec[h.i] = {it, 
			vec[h.ak] = 
		}	
	}	

	return -1;
}
