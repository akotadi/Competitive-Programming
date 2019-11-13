#include <bits/stdc++.h>

#define rep(_,n) for(auto _{0}; _ < n; _++)
#define fi first
#define se second
#define MAXN 21
#define SIZE 11
#define INF (1 << 30)
#define LIMIT (1 << 10)

using namespace std;

typedef pair<int, int> PII;

struct pairhash{
	template <class T1, class T2>
	size_t operator() (const pair<T1, T2> &p) const {
		auto h1 = hash<T1>{}(p.fi);
		auto h2 = hash<T2>{}(p.se);
		return h1 ^ h2;
	}
};

int w, h;
vector< vector<char> > a;
bool visited[MAXN][MAXN];
int dist[SIZE][MAXN][MAXN];
int dp[SIZE][LIMIT];
vector<PII> dirty;
int mskLimit;

int movX[] = {-1, 0, 1, 0}, movY[] = {0, 1, 0, -1};

bool isValid(int x, int y){
	if(x < 0 || x == h) 
		return false;
	if(y < 0 || y == w)
		return false;
	return a[x][y] != 'x';
}

void calcDist(int index){
	rep(i, h)
		rep(j, w)
			dist[index][i][j] = INF;
	int x = dirty[index].fi, y = dirty[index].se;
	queue<PII> bfs;
	memset(visited, false, sizeof(visited));
	bfs.push({x,y});
	visited[x][y] = true;
	dist[index][x][y] = 0;
	while(!bfs.empty()){
		auto curr = bfs.front();
		bfs.pop();
		rep(i, 4){
			int nx = curr.fi+movX[i], ny = curr.se+movY[i];
			if(visited[nx][ny] || !isValid(nx, ny))
				continue;
			visited[nx][ny] = true;
			dist[index][nx][ny] = dist[index][curr.fi][curr.se] + 1;
			bfs.push({nx, ny});
		}
	}
}

bool isSet(int n, int i){
	return (n & (1 << i));
}

int setBit(int n, int i){
	return (n | (1 << i));
}

int recursive(int ind, int msk){
	if(msk == mskLimit)
		return 0;
	if(dp[ind][msk] == -1){
		int result = INF;
		rep(i, dirty.size())
			if(!isSet(msk, i))
				if(dist[ind][dirty[i].fi][dirty[i].se] != INF)
					result = min(result, recursive(i, setBit(msk, i)) + dist[ind][dirty[i].fi][dirty[i].se]);
		dp[ind][msk] = result;
	}

	return dp[ind][msk];
}

void solve(){
	a.clear();
	a.resize(h, vector<char>(w));
	int counter = 0;
	dirty.clear();
	rep(i,h) 
		rep(j, w){
			char c;
			cin >> c;
			if(c == '*')
				dirty.push_back({i,j});
			if(c == 'o')
				dirty.insert(dirty.begin(), {i,j});
			a[i][j] = c;
		}
	mskLimit = (1 << dirty.size()) - 1;
	rep(i, dirty.size()) calcDist(i);
	memset(dp, -1, sizeof(dp));
	int result = recursive(0, 1);
	cout << ((result == INF)?(-1):(result)) << endl;
}

int main() {
	while(cin >> w >> h && w != 0 && h != 0)
		solve();
	return 0;
}
