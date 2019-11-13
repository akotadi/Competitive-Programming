#include <bits/stdc++.h>

using namespace std;

#define MAXN 26

bool check[MAXN];

int main (){
	unordered_map<char, bool> check;
	int n;
	cin >> n;
	char aux;
	for(auto i{0}; i < n; i++){
		cin >> aux;
		check[i] = (aux == 'T');
	}
	stack<bool> values;
	while(cin >> aux){
		switch(aux){
			case '*':
			case '+':
				{
					auto v1 = values.top();
					values.pop();
					auto v2 = values.top();
					values.pop();
					values.push((aux == '*')?(v1 and v2):(v1 or v2));
					break;
				}
			case '-':
				{
					auto v = values.top();
					values.pop();
					values.push(!v);
					break;
				}
			default:
				values.push(check[aux - 'A']);
		}
	}

	cout << ((values.top())?('T'):('F')) << endl;
	return 0;
}
