#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	int a, b, n;
	while(t--){
		cin >> a >> b >> n;
		n %= 3;
		cout << ((n == 0)?(a):((n == 1)?(b):(a xor b))) << endl;
	}
	return 0;
}
