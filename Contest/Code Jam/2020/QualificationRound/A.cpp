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

typedef vector<int> VI;
typedef vector<VI> VVI;

int tcs;
#define tcsolve() cin >> tcs; REP(tc,tcs) solve(tc);

#define MAXN 100000005
#define SIZE 1000001

VVI a;

void precalc(){
    
}

void solve(int t){
    int n;
    cin >> n;
    a.clear();
    a.resize(n, VI(n));
    for(auto &r : a){
        for(auto &num : r){
            cin >> num;
        }
    }

    bool check_r[n], check_c[n], f_c, f_r;
    int n_c = 0, n_r = 0, n_t = 0;
    REP(i,n){
        n_t += a[i][i];
        CLR0(check_r);
        CLR0(check_c);
        f_c = true;
        f_r = true;
        REP(j,n){
            if(f_r){
                if(check_r[a[i][j] - 1]){
                    f_r = false;
                    n_r++;
                }else
                    check_r[a[i][j] - 1] = true;
            }
            if(f_c){
                if(check_c[a[j][i] - 1]){
                    f_c = false;
                    n_c++;
                }else
                    check_c[a[j][i] - 1] = true;
            }
        }
    }

    cout << "Case #" << t+1 << ": " << n_t << " " << n_r << " " << n_c << endl;
    // printf("Case #%d: %d %d %d\n", t+1, n_t, n_r, n_c);
}

int main(){

    fastio;

    // compile program
    tcsolve();
    // solve();

    return 0;
}