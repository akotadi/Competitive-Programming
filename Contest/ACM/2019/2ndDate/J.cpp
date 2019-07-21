#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAXN ((1 << 10))
#define INF 1<<30

typedef long long int lli;

typedef pair<int, int> Factor;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, cub[MAXN + 1] = {0};
int n;

int PrimeFactors(int a){
	int counter = 0, result = 0;
	while(!(a & 1)) ++counter, a>>=1;
	if(counter & 1) result |= 1;
	counter = 0;
	for(int i = 1; i < 9; ++i){
		while(!(a % primes[i])) ++counter, a /= primes[i];
		if(counter & 1) result |= (1 << i);
		counter = 0;
	}
	return result;
}

int dp(int index, int msk){
	if(index == MAXN) return (msk == 0)?0:-INF;
	if(cub[index] == 0) return dp(index + 1, msk);
	if(cub[index] & 1) return max(cub[index] + dp(index + 1, msk ^ index), cub[index] - 1 + dp(index + 1, msk));
	else return max(cub[index] + dp(index + 1, msk), cub[index] - 1 + dp(index + 1, msk ^ index));
}

int main(){
	fastio;

	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for(auto& it : a) cub[PrimeFactors(it)]++;

	cout << dp(0, 0) << endl;

	return 0;
}