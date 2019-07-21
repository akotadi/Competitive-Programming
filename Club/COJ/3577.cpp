/********   Header Files ********/

// Include all the libraries
#include <bits/stdc++.h>



/********   Definitions for our program, including constants and typedef   ********/

// Replace use std:: with the standard C++.
using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// Short names
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'

typedef vector<int> VI;



/********   Main part of the program   ********/

int l, s, m, d, b;

void precalc(){
    // 
}

void solve(){
    VI nS(s, 0), nM(m, 0), nD(d, 0), nB(b, 0);
    for(auto& n : nS) cin >> n;
    for(auto& n : nM) cin >> n;
    for(auto& n : nD) cin >> n;
    for(auto& n : nB) cin >> n;
    unordered_map<int,int> check;
    int result = 0;
    for(auto& n : nS)
        for(auto& m : nM)
            check[l - (n + m)]++;
    for(auto& n : nD)
        for(auto& m : nB){
            for(auto& x : check)
                if(n + m <= x.fi) result+=x.se;
        }
   cout << result << endl;

}

int main(){

    fastio;

    // compile program
    // tcsolve();
    while(cin >> l >> s >> m >> d >> b){
        if(!(l || s || m || d || b)) break;
        solve();
    }

    return 0;
}