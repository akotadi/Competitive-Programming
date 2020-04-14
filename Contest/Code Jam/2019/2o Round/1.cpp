#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	int index = 1;
	while(t--){
		int r, c;
		cin >> r >> c;
		cout << "Case #" << index++ << ": ";
		if (r == c && r < 4) cout << "IMPOSSIBLE" << endl;
		else{
			int aux1 = min(r, c), aux2 = max(r, c);
			if ((aux1 == 2 && aux2 < 5) || (aux1 == 3 && aux2 < 4)) cout << "IMPOSSIBLE" << endl;
			else{
				cout << "POSSIBLE" << endl;
				vector<pair<int,int>> a;
				for (int i = 1; i <= aux2; ++i)
				{
					for (int j = 1; j <= aux1; ++j)
					{
						// cout << j << " " << ((j&1)?i:(((i+1)%aux2)+1)) << endl;
						a.emplace_back(make_pair(j, ((j&1)?i:(((i+1)%aux2)+1))));
					}
				}
				for (std::vector<pair<int,int>>::iterator i = a.begin() + 1; i != a.end(); ++i)
				{
					if((abs((*i).first - (*i).second) == abs((*(i-1)).first - (*(i-1)).second)) || (abs((*i).first + (*i).second) == abs((*(i-1)).first + (*(i-1)).second))) {
						cout << (*i).first << " : " << (*i).second << endl;
						cout << 1 << endl;
					}
					// if(((*i).first - (*i).second == abs((*(i-1)).first) - (*(i-1)).second) || (abs((*i).first + (*i).second) == abs((*(i-1)).first) + (*(i-1)).second)) {
					// 	cout << (*i).first << " : " << (*i).second << endl;
					// 	cout << 1 << endl;
					// }
				}
			}
		}
	}
	return 0;
}