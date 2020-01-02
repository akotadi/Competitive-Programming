#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector< pair<int, int> > a(n);
	int aux;
	for(int i = 0; i < a.size(); i++){ 
		cin >> aux;
		a[i] = {aux, i};
	}
	sort(a.begin(), a.end(), greater< pair<int, int> >());
	int result = 0;
	for(int i = 0; i < a.size(); i++){
		result += (a[i].first*i + 1);
	}
	cout << result << endl;
	for(const auto& it : a)
		cout << it.second+1 << " ";
	cout << endl;
	return 0;
}
