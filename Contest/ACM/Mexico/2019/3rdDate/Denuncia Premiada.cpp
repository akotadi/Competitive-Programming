#include <bits/stdc++.h>

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}

using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f
#define CLR0(a) memset(a, 0, sizeof(a))
#define CLRINF(a) memset(a, 0x3f3f3f3f, sizeof(a))
#define FOR(i, a, b) for (int i=a ; i<b ; i++)
#define REP(i, b) FOR(i, 0, b)
#define fi first
#define se second

int n, k;
int father[MAXN], height[MAXN], lChild[MAXN];
vector< vector<int> > adj;

int calcHeight(int index){
	if(height[index] == 0){
		for(const auto &ch : adj[index]){
			int aux = calcHeight(ch);
			height[index] = max(height[index], aux);
			lChild[index] = (height[index] == aux)?(ch):(lChild[index]);
		}
		height[index]++;
	}

	return height[index];
}

int main () {
	cin >> n >> k;
	adj.resize(n);
	father[0] = -1;
	for(auto i{1}; i < n; i++){
		cin >> father[i];
		adj[--father[i]].push_back(i);
	}
#ifdef DEBUG
	REP(i, n) cout << father[i] << " ";
	cout << endl << endl;
	REP(i, n){
		for(const auto& n : adj[i]) cout << n << " ";
		cout << endl;
	}
	cout << endl;
#endif
	CLR0(height);
	CLRINF(lChild);
	REP(i, n) calcHeight(i);
#ifdef DEBUG
	REP(i, n) cout << i << "-" << height[i] << ":" << lChild[i] << endl;
	cout << endl;
#endif
	multimap<int, int> check;
	unordered_set<int> visited;
	REP(i, n) check.insert({height[i], i});
#ifdef DEBUG
	for(const auto& it : check) cout << it.fi << ":" << it.se << endl;
	cout << endl;
#endif

	int res = 0;
	for(auto it = check.rbegin(); it != check.rend(); it++){
		if(visited.find((*it).se) != visited.end())
			continue;
		visited.insert((*it).se);
#ifdef DEBUG
		cout << (*it).fi << ":" << (*it).se << endl;
#endif
		for(auto aux = lChild[(*it).se]; aux != INF; aux = lChild[aux]){
#ifdef DEBUG
			cout << "\t" << aux << endl;
#endif
			visited.insert(aux);
		}
		res += (*it).fi;
		if(--k == 0)
			break;
	}	
	cout << res << endl;

	return 0;
}
