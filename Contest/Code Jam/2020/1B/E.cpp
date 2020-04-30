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

#define MAXN 51
#define SIZE 1000001

int n, k, idx;
VI check;
unordered_map<int, int> cnt;

bool fillMatrix(VVI &a, vector<vector<bool>> b_r, vector<vector<bool>> b_c, int x, int y){
    if(x == n-1 && y == n-1){
        return true;
    }else if(x == n)
        return fillMatrix(a, b_r, b_c, 0, y+1);
    else if(a[x][y])
        return fillMatrix(a, b_r, b_c, x+1, y);

    FOR(i,0,n){
        if(b_r[x][i] || b_c[y][i])
            continue;
        a[x][y] = i+1;
        b_r[x][i] = true;
        b_c[y][i] = true;
        if(fillMatrix(a, b_r, b_c, x+1, y))
            return true;
        b_r[x][i] = false;
        b_c[y][i] = false;
        a[x][y] = 0;
    }

    return false;
}

int maxCnt(){
    unordered_map<int,int> mymap;
    REP(i,n)
        mymap[check[i]]++;

    int ans = -1;
    for(const auto &p : mymap)
        ans = max(ans, p.se);

    return ans;
}

bool partitionNumber(int num, int maxNum, int index){ 
    if(num == 0){
        if(index != n || maxCnt() == n-1)
            return false;

        return true;
    }

    for (int i = maxNum; i >= 1; i--){ 
        if(i > num){ 
            continue; 
        } else if(i <= num){
            if(index < check.size()){
                check[index] = i; 
            }
            else{
                check.pb(i);
            }

            if(partitionNumber(num - i, i, index + 1))
                return true;
        } 
    } 

    return false;
}

void solve(int t){

    cin >> n >> k;
    if(k == n+1 || k == pow(n,2)-1 || (n == 3 && (k != n && k != pow(n,2) && k != n*2))){
        cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
        return;
    }

    check.clear();
    if(!partitionNumber(k, n, 0)){
        cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
        return;
    }

    VVI a(n, VI(n, 0));
    vector<vector<bool>> b_r(n, vector<bool>(n,false));
    vector<vector<bool>> b_c(n, vector<bool>(n,false));
    REP(i,n){
        a[i][i] = check[i];
        b_r[i][check[i]-1] = true;
        b_c[i][check[i]-1] = true;
    }

    if(fillMatrix(a, b_r, b_c, 0, 0)){
        cout << "Case #" << t+1 << ": POSSIBLE" << endl;
        for(const auto &r : a){
            for(const auto &num : r){
                cout << num << " ";
            }
            cout << endl;
        }
    }else
        cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
}

int main(){

    fastio;

    // compile program
    tcsolve();
    // solve(1);

    return 0;
}