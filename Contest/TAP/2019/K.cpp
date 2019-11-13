#include <bits/stdc++.h>

#define pb push_back
#define all(a) a.begin(),a.end()
#define fi first
#define se second

using namespace std;

int main(){
	int n;
	cin >> n;
	vector< pair<int, int> > a, b;
	char c;
	int x, y;
	for(auto i{0}; i < n; i++){
		cin >> c >> x >> y;
		if(c == 'J')
			a.pb({x, y});
		else
			b.pb({x,y});
	}
	if(a.size() == 0 || b.size() == 0) 
		return 0;
	sort(all(a));
	sort(all(b));
	int maxA = 0, maxB = 0, index = 0, result = 0;
	for(const auto& it : a){
		while(index < b.size() && b[index].fi <= it.fi)
			maxB = max(maxB, b[index++].se);
		result = max(result, min(it.se, maxB) - it.fi);
	}
	index = 0;
	for(const auto& it : b){
		while(index < a.size() && a[index].fi <= it.fi)
			maxA = max(maxA, a[index++].se);
		result = max(result, min(it.se, maxA) - it.fi);
	}

	cout << result << endl;

	return 0;
}
