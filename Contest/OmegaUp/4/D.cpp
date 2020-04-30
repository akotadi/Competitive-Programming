#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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

#define tcsolve() int tcs; cin>>tcs; while(tcs--) solve();

#define MAXN 100000005
#define SIZE 1000001

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

void solve(){
    int l, m;
    cin >> l >> m;
    VVI a(l, VI(l, -1));
    REP(i,m){
        int x, y, s;
        cin >> x >> y >> s;
        a[x-1][y-1] = s;
    }

    unordered_set<PII, pair_hash> check;
    Long ans = 0;
    REP(i,l){
        REP(j,l){
            if(a[i][j] == -1){
                ans = 0;
                a[i][j] = 1;
                int curr = 0;
                REP(k,l){
                    if(a[i][k] == 0) curr++;
                    else{
                        ans += (curr >= 5);
                        curr = 0;
                    }
                }

                curr = 0;
                REP(k,l){
                    if(a[k][l] == 0) curr++;
                    else{
                        ans += (curr >= 5);
                        curr = 0;
                    }
                }

                curr = 0;
                int x = i+1, y = j+1;
                while(x < l && y < l && a[x][y] == 0){
                    curr++, x++, y++;
                }
                x = i-1, y = j-1;
                while(x >= 0 && y >= 0 && a[x][y] == 0){
                    curr++, x--, y--;
                }
                ans += (curr >= 5);

                curr = 0;
                x = i+1, y = j-1;
                while(x < l && y >= 0 && a[x][y] == 0){
                    curr++, x++, y--;
                }
                x = i-1, y = j+1;
                while(x >= 0 && y < l && a[x][y] == 0){
                    curr++, x--, y++;
                }
                ans += (curr >= 5);

                if(ans > 0) check.insert({i,j});
                a[i][j] = -1;
            }
        }
    }

    for(const auto &p : check) cout << p.fi << " " << p.se << endl;
}

int main(){

    fastio;

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