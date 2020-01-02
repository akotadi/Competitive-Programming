#include <bits/stdc++.h>

using namespace std;

typedef int64_t lli;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &it : a) cin >> it;
	int maxNumber = *max_element(a.begin(), a.end());
	int numGCD = maxNumber - a.front();
	for(int i = 1; i < a.size(); i++)
		numGCD = __gcd(numGCD, maxNumber - a[i]);
	lli result = 0;
	for(const auto &num : a)
		result += (maxNumber - num);
	cout << result / numGCD << " " << numGCD << endl;
	return 0;
}
