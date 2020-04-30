#include <bits/stdc++.h>

using namespace std;

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}

#define read(type) readNumber<type>()
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

void precalc(){
    
}

void solve(){
    int n;
    cin >> n;

    VI a(n);
    REP(i,n) cin >> a[i];

    VVI t(n);
    int x, y;
    REP(i,n-1){
        cin >> x >> y;
        x--, y--;
        t[x].pb(y);
        t[y].pb(x);
    }

    Double sum = 0, paths = 0;
    vector<bool> vis(n,false);
    REP(i,n){
        vis[i] = true;
        vector<bool> aux(n,false);
        queue< pair<int, PII> > q;
        q.push({i, {a[i], a[i]}});
        while(!q.empty()){
            auto next = q.front();
            q.pop();
            if(aux[next.fi]) continue;
            aux[next.fi] = true;
            if(!vis[next.fi]){
                sum += next.se.fi - next.se.se;
                paths += 1.0;
            }
            for(const auto v : t[next.fi]){
                q.push({v, {max(next.se.fi, a[v]), min(next.se.se, a[v])}});
            }
        }
    }

    cout << prec(9, sum / (paths + n)) << endl;
}

int main(){

    // fastio;

    #ifdef DEBUG
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        // freopen("log.txt", "w", stderr);
    #endif

    // ofstream fout("bubble.out");
    // ifstream fin("bubble.in");
    // fin >> N;

    // compile program
    // tcsolve();
    solve();

    #ifdef DEBUG
        // cout << "Execution time : " << tick() << endl ;
        fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    #endif

    return 0;
}