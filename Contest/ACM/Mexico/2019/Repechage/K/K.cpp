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
	int n, nList;
	VVI adjList, matrix, incList, sorted;
	VI indegree, visited, map, index;

	Graph(int V): n(V), nList(0), matrix(V, VI(V)), adjList(V), incList(V), visited(V, 0), indegree(V, 0), map(V, 0){}

	void addEdge(int u, int v){
		++indegree[v];
		adjList[u].pb(v);
		incList[v].pb(u);
	}

	bool hasCycle(int u, int prev){
		visited[u] = 1;
		for(auto &v : adjList[u])
			if(visited[v] != 2 && (visited[v] || hasCycle(v, u)))
				return true;
		visited[u] = 2;
		return false;
	}

	bool hasCycle(){
		rep(u,n)
			if(!visited[u] && hasCycle(u, -1))
				return true;
		return false;
	}

	void dfs(int u, set<int> &check){
		queue<int> q;
		q.push(u);
		visited[u] = 1;
		while(!q.empty()){
			int curr = q.front();
			q.pop();
			if(visited[curr] == 2) continue;
			if(indegree[curr] == 0) check.insert(curr);
			for(const auto &v : adjList[curr]){
				if(!visited[v]) q.push(v);
				visited[v] = 1;
			}
			for(const auto &v : incList[curr]){
				if(!visited[v]) q.push(v);
				visited[v] = 1;
			}
			visited[curr] = 2;
		}
	}

	void toposort(){
		visited.clear();
		visited.resize(n, 0);
		rep(i, n){
			if(visited[i]) continue;
			set<int> check;
			VI partial;
			dfs(i, check);
			while(!check.empty()){
				int u = *check.begin();
				check.erase(check.begin());
				map[u] = nList;
				partial.pb(u);
				for(auto &v : adjList[u])
					if(--indegree[v] == 0) check.insert(v);
			}
			sorted.pb(partial);
			index.pb(0);
			nList++;
		}

		VI result(n);
		int cnt = 0;
		visited.clear();
		visited.resize(n, 0);
		rep(i,n){
			if(visited[i]) continue;
			while(sorted[map[i]][index[map[i]]] != i){
				result[sorted[map[i]][index[map[i]]]] = ++cnt;
				visited[sorted[map[i]][index[map[i]]]] = 1;
				index[map[i]]++;
			}
			index[map[i]]++;
			result[i] = ++cnt;
			visited[i] = 1;
		}
		rep(i,n){
			cout << result[i];
			if(i < n-1)
				cout << " ";
			else
				cout << endl;
		}
	}
};

int main(){
	int n;
	cin >> n;
	Graph g(n);
	rep(i,n)
		rep(j,n){
			cin >> g.matrix[i][j];
			if(g.matrix[i][j] == 1)
				g.addEdge(i, j);
		}
	if(g.hasCycle())
		cout << -1 << endl;
	else
		g.toposort();

	return 0;
}
