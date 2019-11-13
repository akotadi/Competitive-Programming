#include <bits/stdc++.h>

#define MAXN 2005
#define fi first
#define se second

using namespace std;

struct pairhash {
	template <class T1, class T2>
		size_t operator() (const pair<T1, T2> &p) const{
			auto h1 = hash<T1>{}(p.first);
			auto h2 = hash<T2>{}(p.second);
			return h1 ^ h2;
		}
};

bool visited[MAXN][MAXN];

int movX[] = {-1, 0, 1, 0}, movY[] = {0, 1, 0, -1};


int h, w;
vector<string> a;
unordered_set< pair<int, int>, pairhash > centers, fakeC;

bool isValid(int x, int y){
	if(x == -1 || x == h) return false;
	if(y == -1 || y == w) return false;
	return a[x][y] == '*' && !visited[x][y];
}

void floodFill(int x, int y){
	if(!isValid(x, y)) return;
	visited[x][y] = true;
	for(auto i{0}; i < 4; i++){
		floodFill(x + movX[i], y + movY[i]);
	}
}

int leftB(int x, int y){
	auto flag{true};
	auto counter{0};
	for(auto i{y}; i >= 0; i--, counter++){
		if(a[x][i] == '.')
			break;
		flag = (a[x-1][i] == '.') && (a[x+1][i] == '.');
		if(!flag)
			break;
	}
	return ((flag)?(counter):(-1));
}

int rightB(int x, int y){
	auto flag{true};
	auto counter{0};
	for(auto i{y}; i < w; i++, counter++){
		if(a[x][i] == '.')
			break;
		flag = (a[x-1][i] == '.') && (a[x+1][i] == '.');
		if(!flag)
			break;
	}
	return ((flag)?(counter):(-1));
}

int topB(int x, int y){
	auto flag{true};
	auto counter{0};
	for(auto i{x}; i >= 0; i--, counter++){
		if(a[i][y] == '.')
			break;
		flag = (a[i][y-1] == '.') && (a[i][y+1] == '.');
		if(!flag)
			break;
	}
	return ((flag)?(counter):(-1));
}

int botB(int x, int y){
	auto flag{true};
	auto counter{0};
	for(auto i{x}; i < h; i++, counter++){
		if(a[i][y] == '.')
			break;
		flag = (a[i][y-1] == '.') && (a[i][y+1] == '.');
		if(!flag)
			break;
	}
	return ((flag)?(counter):(-1));
}

bool isCrucifix(int x, int y){
	int left = leftB(x, y-1), right = rightB(x, y+1), top = topB(x-1, y), bot = botB(x+1, y);
	floodFill(x, y);
	return (left == right && left == top) && (left < bot) && (left != -1);
}

int main () {
	memset(visited, 0, sizeof(visited));
	cin >> h >> w;
	a.resize(h);
	for(auto& s : a) cin >> s;
	if(h < 4 || w < 3){
		cout << 0 << endl;
		return 0;
	}
	auto result{0};
	for(auto i{1}; i < h-1; i++){
		for(auto j{1}; j < w-1; j++){
			if(visited[i][j])
				continue;
			if(a[i][j] == '*'){
				bool flag = true;
				for(auto k{0}; k < 4; k++){
					if(a[i+movX[k]][j+movY[k]] != '*')
						flag = false;
				}
				if(flag)
					result += isCrucifix(i, j);
			}
		}
	}
	cout << result << endl;
	return 0;
}
