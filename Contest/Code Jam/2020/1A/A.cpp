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

VVI a;

vector<string> split(const string& s)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, '*'))
      tokens.pb(token);
   return tokens;
}

void solve(int t){
    int n;
    cin >> n;

    vector<string> a, b, c;
    REP(i,n){
        string s;
        cin >> s;
        auto tokens = split(s);
        if(s.front() == '*' && s.back() == '*'){
            for(const auto &word : tokens)
                a.pb(word);
        }
        else if(s.front() == '*'){
            string aux = tokens.back();
            reverse(all(aux));
            b.pb(aux);
            REP(j,tokens.size()-1)
                a.pb(tokens[j]);
        }
        else if(s.back() == '*'){
            c.pb(tokens.front());
            FOR(j,1,tokens.size())
                a.pb(tokens[j]);
        }
        else{
            string aux = tokens.back();
            reverse(all(aux));
            b.pb(aux);
            c.pb(tokens.front());
            FOR(j,1,tokens.size()-1)
                a.pb(tokens[j]);
        }
    }

    sort(all(b));
    FOR(i,1,b.size()){
        REP(j,min(b[i].size(), b[i-1].size())){
            if(b[i][j] != b[i-1][j]){
                cout << "Case #" << t+1 << ": *" << endl;
                return;
            }
        }
    }
    sort(all(c));
    FOR(i,1,c.size()){
        REP(j,min(c[i].size(), c[i-1].size())){
            if(c[i][j] != c[i-1][j]){
                cout << "Case #" << t+1 << ": *" << endl;
                return;
            }
        }
    }

    cout << "Case #" << t+1 << ": ";
    if(!c.empty())
        cout << c.back();
    for(const auto &word : a)
        cout << word;
    if(!b.empty()){
        string word = b.back();
        reverse(all(word));
        cout << word;
    }
    cout << endl;
    // printf("Case #%d: %d %d %d\n", t+1, n_t, n_r, n_c);
}

int main(){

    fastio;

    // compile program
    tcsolve();
    // solve();

    return 0;
}