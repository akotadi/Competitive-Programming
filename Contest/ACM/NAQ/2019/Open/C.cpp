#include <bits/stdc++.h>

using namespace std;

#define prec(n,a) fixed << setprecision(n) << a

typedef long long int lli;

int main (){
	map<int, int> votesA, votesB;
	int p, d;
	cin >> p >> d;
	lli nVotes = 0LL;
	while(p--){
		int a, b;
		cin >> d >> a >> b;
		nVotes += (a+b);
		votesA[d] += a;
		votesB[d] += b;
	}
	lli wA = 0LL, wB = 0LL;
	for(const auto &it : votesA){
		lli total = it.second + votesB[it.first];
		if(it.second > votesB[it.first]){
			wA += (it.second - ((total >> 1) + 1));
			wB += votesB[it.first];
			cout << "A " << it.second - ((total >> 1) + 1) << " " << votesB[it.first] << endl;
		}else{
			wA += it.second;
			wB += (votesB[it.first] - ((total >> 1) + 1));
			cout << "B " << it.second << " " << votesB[it.first] - ((total >> 1) + 1) << endl;
		}
	}
	double result = (double)abs(wA - wB);
	result /= nVotes;
	cout << prec(8,result) << endl; 
	return 0;
}
