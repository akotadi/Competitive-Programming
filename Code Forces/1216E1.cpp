#include <bits/stdc++.h>

using namespace std;

vector<int> a;

typedef int64_t lli;

int binary_search(int target){
	lli left = 0, right = 1414213562, mid, result;
	while(left+1 < right){
		mid = left + ((right - left) >> 1);
		result = ((mid * (mid-1)) >> 1);
		if(result >= target) right = mid;
		else left = mid;
	}

	return ((left * (left-1)) >> 1);
}

int main(){
	int q;
	cin >> q;
	while(q--){
		int k;
		cin >> k;
#ifdef DEBUG
		cout << binary_search(k) << endl;
#endif
		if(k != 1)
			k -= binary_search(k);
		cout << k << endl;
	}
	return 0;
}
