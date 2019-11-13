#include <bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector< vector<int> > a(n, vector<int>(m, -1));
	vector< vector<double> > b(n, vector<double>(n, 0.0));
	rep(i,n){
		int aux;
		cin >> aux;
		while(aux--){
			int x, y;
			cin >> x >> y;
			a[i][x-1] = y;
		}
	}
	rep(i,n){
		double aux = 0.0;
		forn(j,i+1,n){
			aux = 0.0;
			rep(k,m){
				if(a[i][k] == -1 || a[j][k] == -1)
					continue;
				aux += pow(a[i][k] - a[j][k], 2);
			}
			aux = sqrt(aux);
			b[i][j] = aux;
			b[j][i] = aux;
		}
	}
	rep(i,n){
		int row = -1;
		double maxD = -1.0;
		rep(j,n){
			if(i == j) 
				continue;
			if(b[i][j] > maxD){
				maxD = b[i][j];
				row = j;
			}
		}
		int res = -1, curr = -1;
		rep(j,m){
			if(a[i][j] == -1 && a[row][j] > curr){
				curr = a[row][j];
				res = j;
			}
		}
		cout << res+1 << endl;
	}
	return 0;
}
