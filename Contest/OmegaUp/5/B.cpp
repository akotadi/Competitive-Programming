#include <bits/stdc++.h>

using namespace std;

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}

#define prec(n,a) fixed << setprecision(n) << a
#define FORI(i, a, b, in) for (int i=a ; i<b ; i+=in)
#define RFORI(i, a, b, in) for (int i=a ; i>=b ; i-=in)
#define FOR(i, a, b) for (int i=a ; i<b ; i++)
#define RFOR(i, a, b) for (int i=a ; i>=b ; i--)
#define REP(i, b) FOR(i, 0, b)
#define RREP(i, a) RFOR(i, a, 0)
#define ABS(x) ((x)<0?-(x):(x))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR0(a) memset(a, 0, sizeof(a))
#define CLRINF(a) memset(a, 0x3f3f3f3f, sizeof(a))
#define GMOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define sz(a) int((a).size())

typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef map<int,int> MPII;
typedef set<int> SETI;

#define tcsolve() int tcs; cin >> tcs; while(tcs--) solve();

#define MAXN 100000005
#define SIZE 1005

int a[SIZE][SIZE];

void aux(VI w, VI p, int n){
    memset(a, 0, sizeof(a));
    REP(i,n+1){
    	REP(j,1002){
		if(i == 0 || j == 0) 
			a[i][j] = 0;
		else if(w[i-1] <= j)
			a[i][j] = max(p[i-1] + a[i-1][j-w[i-1]], a[i-1][j]);
		else 
			a[i][j] = a[i-1][j];
	}
    }
}

void solve(){
    int n;
    while(cin >> n){
    	VI p(n), w(n);
	REP(i,n) cin >> p[i] >> w[i];
	aux(w, p, n);

	int m;
	cin >> m;
#ifdef DEBUG
	cout << m << endl;
#endif
	VI c(m);
	REP(i,m) cin >> c[i];
	
	Long ans = 0;
	REP(i,m) ans += a[n][c[i]];
	cout << ans << endl;
    }
}

int main(){

    // fastio;i

    // compile program
    // tcsolve();
    solve();

    #ifdef DEBUG
        // cout << "Execution time : " << tick() << endl ;
        fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    #endif

    return 0;
}
