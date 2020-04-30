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
#include <limits>

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
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define sz(a) int((a).size())

typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;

typedef vector<int> VI;
typedef vector<VI> VVI;

int tcs,a,b;
#define tcsolve() cin >> tcs >> a >> b; REP(tc,tcs) solve(tc);

#define MAXN 100000005
#define SIZE 1000001

void solve(int t){

    int s, e, m;
    string res;
    bool f_x = true, f_y = true;

    s = 0, e = pow(10,9);
    while(s < e){
        m = s + ((e - s) >> 1);
        cout << m << " " << 0 << endl;
        cin >> res;
        if(res == "CENTER" || res == "WRONG") return;
        if(res == "HIT") s = m+1;
        else r = m;
    }
    if(s = 0){
        f_x = false;
        s = 0, e = pow(10,9);
        while(s < e){
            m = s + ((e - s) >> 1);
            cout << -m << " " << 0 << endl;
            cin >> res;
            if(res == "CENTER" || res == "WRONG") return;
            if(res == "HIT") s = m+1;
            else r = m;
        }
    }

    s = 0, e = pow(10,9);
    while(s < e){
        m = s + ((e - s) >> 1);
        cout << 0 << " " << m << endl;
        cin >> res;
        if(res == "CENTER" || res == "WRONG") return;
        if(res == "HIT") s = m+1;
        else r = m;
    }
    if(s = 0){
        f_y = false;
        s = 0, e = pow(10,9);
        while(s < e){
            m = s + ((e - s) >> 1);
            cout << 0 << " " << -m << endl;
            cin >> res;
            if(res == "CENTER" || res == "WRONG") return;
            if(res == "HIT") s = m+1;
            else r = m;
        }
    }

    

}

int main(){

    fastio;

    // compile program
    tcsolve();
    // solve();

    return 0;
}