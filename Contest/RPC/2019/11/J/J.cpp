#include <bits/stdc++.h>

#define pb push_back
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)
#define fi first
#define se second

using namespace std;

typedef int64_t lli;

typedef pair<lli, lli> PII;
typedef vector<lli> VI;
typedef vector<VI> VVI;
typedef vector< vector<PII> > VII;

struct Graph{
	int n;
	VVI adjList, avg, ans;
	VII accum;
	VI visited, sorted;

	Graph(int V): n(V), adjList(V), avg(V, VI(V)), ans(V, VI(V, -1)), accum(V, vector<PII>(V, {0,0})), visited(V, false) {}

	void addEdge(int u, int v){
		adjList[u].pb(v);
	}

	void toposort(int u){
		visited[u] = true;
		for(const auto &v : adjList[u])
			if(!visited[v])
				toposort(v);
		sorted.pb(u);
	}

	void toposort(){
		rep(u, n)
			if(!visited[u])
				toposort(u);
		reverse(sorted.begin(), sorted.end());
	}

	void solve(){
		forn(i, 1, n){
			for(int j = i-1; j >= 0; j--){
				int u = sorted[j];
				int v = sorted[i];

				forn(k, j+1, i){
					int w = sorted[k];
					if(ans[w][v] > 0){
						accum[u][v].fi += accum[u][w].fi;
						accum[u][v].se += accum[u][w].se + accum[u][w].fi * ans[w][v];
					}
				}

				if(avg[u][v] == -1)
					continue;

				if(accum[u][v].fi > 0 && accum[u][v].se == avg[u][v] * accum[u][v].fi){
					ans[u][v] = -1;
					continue;
				}else{
					lli w = avg[u][v] * (accum[u][v].fi + 1) - accum[u][v].se;
					ans[u][v] = w;
					accum[u][v].fi++;
					accum[u][v].se += w;
				}

			}
		}
	}
};

int main(){
	int n;
	cin >> n;
	Graph g(n);
	rep(i,n)
		rep(j,n){
			cin >> g.avg[i][j];
			if(g.avg[i][j] > 0)
				g.addEdge(i, j);
		}
	
	g.toposort();
	g.solve();

	rep(i,n){
		rep(j, n){
			cout << g.ans[i][j];
			if(j < n-1) cout << " ";
		}
		cout << endl;
	}

	return 0;
}
