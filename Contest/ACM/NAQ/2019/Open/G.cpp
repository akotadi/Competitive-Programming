#include <bits/stdc++.h>

#define MAXN 105

using namespace std;

vector<double> values;
vector< vector< vector<double> > > dp;

bool cmp(double& a, double& b){
	return a > b;
}

double recursive(int index, int &maxSend, int accepted){
	if(index == maxSend)
		return (accepted)?(pow((double)accepted, (double)accepted / (double)maxSend)):(0.0);
	
	if(dp[index][maxSend][accepted] == -1.0){
		dp[index][maxSend][accepted] = (values[index]*recursive(index+1, maxSend, accepted+1) + (1.0-values[index])*recursive(index+1, maxSend, accepted));
	} 
	
	return dp[index][maxSend][accepted];
}

int main () {
	int n;
	cin >> n;
	values.resize(n, 0.0);
	dp.resize(MAXN, vector< vector<double> >(MAXN, vector<double>(MAXN, -1.0)));
	for(auto &v : values) cin >> v;
	for(auto &v : values) v /= 100.0;
	sort(values.begin(), values.end(), cmp);
	double maxValue = 0.0;
	for(auto i{1}; i <= n; i++){
		maxValue = max(maxValue, recursive(0, i, 0));
	}

	cout << fixed << setprecision(8) << maxValue << endl;
	return 0;
}
