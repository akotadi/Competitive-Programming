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

#define tcsolve() int tcs=read(int); while(tcs--) solve();

#define MAXN 10005
#define SIZE 1000001

void precalc(){
    // 
}

void solve(){
    string s;
    cin >> s;
    int n_a = 0, n_b = 0, n_c = 0, i = 0;

    if(i == s.size() || s[i] != 'a'){
        cout << "NO" << endl;
        return;
    }
    while(i < s.size() && s[i] == 'a'){
        n_a++;
        i++;
    }
    if(n_a == 0){
        cout << "NO" << endl;
        return;
    }

    if(i == s.size() || s[i] != 'b'){
        cout << "NO" << endl;
        return;
    }
    while(i < s.size() && s[i] == 'b'){
        n_b++;
        i++;
    }
    if(n_b == 0){
        cout << "NO" << endl;
        return;
    }

    if(i == s.size() || s[i] != 'c'){
        cout << "NO" << endl;
        return;
    }
    while(i < s.size() && s[i] == 'c'){
        n_c++;
        i++;
    }
    if(n_c == 0){
        cout << "NO" << endl;
        return;
    }

    if(i == s.size() && (n_c == n_a || n_c == n_b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){

    fastio;

    // compile program
    // tcsolve();
    solve();

    return 0;
}