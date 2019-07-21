#include <bits/stdc++.h>

using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define read(type) readNumber<type>()
// Short names
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'

typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;



/********   Main part of the program   ********/

void precalc(){
    // 
}

void solve(){
    // 
}

int main(){

    fastio;

    Long n, x1, x2, y1, y2;
    cin >> n >> x1 >> x2 >> y1 >> y2;
    Long z1 = abs(x1-y1), z2 = abs(x2-y2);
    Long z = z1+z2;
    Long result = 0;
    if (z == 0) {
        z = 2;
    }
    result = (n-z)/2 + 1;
    if (n < z) {
        cout << 0 << endl;
    }else{
        cout << result << endl;
    }
    return 0;
}