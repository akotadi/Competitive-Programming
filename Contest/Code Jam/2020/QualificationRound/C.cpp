#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

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

int tcs;
#define tcsolve() cin >> tcs; REP(tc,tcs) solve(tc);

#define MAXN 100000005
#define SIZE 1000001

void precalc(){
    
}

struct el{
    int i;
    PII t;

    el(int I, PII T): i(I), t(T){}
};

bool cmp (el e1, el e2) { 
    if(e1.t.fi == e2.t.fi)
        return e1.t.se < e2.t.se;
    return e1.t.fi < e2.t.fi;
}

void solve(int t){
    int n;
    cin >> n;

    vector<el> a(n, el(0,{0,0}));
    vector<char> ans(n, 'F');
    REP(i,n){
        PII aux(0,0);
        cin >> aux.fi >> aux.se;
        el e(i, aux);
        a[i] = e;
    }

    if(n < 2){
        cout << "Case #" << t+1 << ": C" << endl;
        return;
    }

    sort(all(a), cmp);

    int c_t = -1, j_t = -1;
    REP(i,n){
        if(a[i].t.fi >= c_t){
            c_t = a[i].t.se;
            ans[a[i].i] = 'C';
        }else if(a[i].t.fi >= j_t){
            j_t = a[i].t.se;
            ans[a[i].i] = 'J';
        }else{
            cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
            return;
        }
    }

    cout << "Case #" << t+1 << ": ";
    for(const auto &c : ans) cout << c;
    cout << endl;
}

int main(){

    fastio;

    // compile program
    tcsolve();
    // solve();

    return 0;
}