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
#include <string>
#include <sstream>

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

bool isPossible(Long n){
    int k = (int)log2(n);
    bool flag = true;
    REP(i,k)
        if(!(n & (1ll << i))) flag = false;

    return flag;
}

bool isValid(Long a, Long b, Long t){
    Long b_a = __builtin_popcountll(a);
    Long b_b = __builtin_popcountll(b);
    Long b_t = __builtin_popcountll(t);

    return (b_a + b_b == b_t);
}

void solve(int tc_s){
    Long x, y;
    cin >> x >> y;

    bool f_x = x > 0ll, f_y = y > 0ll;
    x = abs(x), y = abs(y);
    Long odd = (x & 1ll) ? x : y, even = (x & 1ll) ? y : x;
    Long t = (x | y), a = (odd + 1ll) | even;
    Long b_a = __builtin_popcountll(a) + 1;
    Long b_t = __builtin_popcountll(t);

    
    string ans = "";
    if(((x + y) & 1ll) && (isPossible(t) || isPossible(a | 1ll))){
        if(!isValid(x, y, t) || 
            (isPossible(a | 1ll) && isValid(odd + 1ll, even, a) && b_a < b_t)){
            if(x & 1ll){
                ans += (f_x ? 'W' : 'E');
                x++;
            }else{
                ans += (f_y ? 'S' : 'N');
                y++;
            }

            t = a;
        }

        while(t != 0ll){
            Long k = t & -t;
            if(x & k){
                ans += (f_x ? 'E' : 'W');
            }
            else{
                ans += (f_y ? 'N' : 'S');
            }
            t = (t & ~k);
        }
    }else ans += "IMPOSSIBLE";

    cout << "Case #" << tc_s+1 << ": " << ans << endl;
}

int main(){

    fastio;

    // compile program
    tcsolve();
    // solve();

    return 0;
}