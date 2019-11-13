#include <bits/stdc++.h>

#define MAXN 300005

using namespace std;

typedef int64_t lli;

const lli mod = 986444689;

lli pmod(lli n){
	n %= mod;
	n += mod;
	return n%mod;
}

bool boss[MAXN+5];
lli fact[MAXN+5];

void precalc(){
	memset(fact, 0, sizeof(fact));
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i < MAXN; ++i)
            fact[i] = pmod(fact[i-1] * i);
}

lli modularInverse(lli a){
	lli r0 = a, r1 = mod, ri, s0 = 1, s1 = 0, si;
	while(r1){
		si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
		ri = r0 % r1, r0 = r1, r1 = ri;
	}
	if(r0 < 0) s0 *= -1;
	return pmod(s0);
}

int comb(int n, int k){
	lli a = fact[n];
	lli b = fact[n-k] * fact[k];
       	b %= mod;
	b = modularInverse(b);
	return pmod(a * b);
}

int days, boxes, aux;
stringstream split;

void solve(){
	cin >> days >> boxes;
	string s1, s2;
	getchar();	
	getline(cin, s1);
	getline(cin, s2);
	split.clear();
	split.str(s2);
	memset(boss, 0, sizeof(boss));
	while (split >> aux){
		if(aux == 0) continue;
		boss[aux] = true;
		boxes -= 2;
	}
	split.clear();
	split.str(s1);
	while (split >> aux){
		if(aux == 0) continue;
		if(!boss[aux]) boxes--;
	}
	if(boxes < 0){
		cout << 0 << endl;
		return;
	}
	cout << (comb(days+boxes-1, days-1)) << endl;
}

int main (){
	precalc();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
