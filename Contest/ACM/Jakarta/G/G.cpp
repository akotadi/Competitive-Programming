#include <bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) forn(i,0,n)

using namespace std;

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}

const int N = 1e5+5;
int n;
int t[2 * N];
int h = sizeof(int) * 8 - __builtin_clz(n);
int d[N];  

void apply(int p, int value) {
  t[p] += value;
  if (p < n) d[p] += value;
}

void build() { 
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void build(int p) {
  while (p > 1) p >>= 1, t[p] = min(t[p<<1], t[p<<1|1]) + d[p];
}

void push(int p) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i] != 0) {
      apply(i<<1, d[i]);
      apply(i<<1|1, d[i]);
      d[i] = 0;
    }
  }
}

void inc(int l, int r, int value) {
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, value);
    if (r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

int query(int l, int r) {
  l += n, r += n;
  push(l);
  push(r - 1);
  int res = 2e9;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t[l++]);
    if (r&1) res = min(t[--r], res);
  }
  return res;
}


int main () {
	int p, m, q;
	cin >> p >> m >> q;
	vector<int> a(m+1);
	vector< vector<int> > b(m);
	int r, e = 0;
	cin >> r;
	forn(i,1,p){
		int aux;
		cin >> aux;
		if(aux < r) e++;
	}
	rep(i,m){
		int aux;
		cin >> aux;
		b[i].resize(aux);
		e -= aux;
		a[i] = e;
		rep(j,aux){
			int aux2;
			cin >> aux2;
			b[i][j] = aux2;
			if(aux2 < r) e++;
		}
	}
	a[m] = e;

	n = m+1;
	rep(i,m+1) t[n+i] = a[i];
	build();
	int x, y, z, last = ((query(0, m) < 0)?0:1);
	rep(i,q){
		cin >> x >> y >> z;
		if(b[x-1][y-1] < r && z > r){
			inc(x, m, -1);
			b[x-1][y-1] = z;
			last = ((query(0, m) < 0)?0:1);
		}else if(b[x-1][y-1] > r && z < r){
			inc(x, m, 1);
			b[x-1][y-1] = z;
			last = ((query(0, m) < 0)?0:1);
		}
	
		cout << last << endl;
	}
	return 0;
}
