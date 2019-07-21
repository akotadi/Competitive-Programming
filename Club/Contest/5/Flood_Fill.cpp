//#pragma GCC optimize("Ofast, unroll-loops")
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <cassert>
#include <functional>
#include <queue>
#include <numeric>
#include <bitset>
#include <iterator>
#include <cstring>

using namespace std;

mt19937 gen(time(NULL));
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define forn(i, n) for (int i = 0; i < n; i++)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define mp make_pair
#define endl '\n'
#define INF 1<<30
#define MAXN 5005

typedef long long ll;

template <typename T = int>  
inline T read() {
    T number = 0, numberSign = 1;
    char currentChar = getchar();
 
    while (currentChar < '0' or currentChar > '9') {
        if (currentChar == '-')  numberSign = -1;
        currentChar = getchar();
    }

    while (currentChar >= '0' and currentChar <= '9') {
        number = (number << 3) + (number << 1) + (currentChar - '0');
        currentChar = getchar();
    }

    return number * numberSign;
}

int dp[MAXN][MAXN];
int a[MAXN];

int main(){
    optimizar_io

    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i = 0; i < MAXN; ++i)
        dp[i][i] = 0;
    for (int i = n; i >= 1; --i)
    {
        for (int j = i; j <= n; ++j)
        {
            if (a[i-1] == a[i])
                dp[i-1][j] = min(dp[i][j], dp[i-1][j]);
            else
                dp[i-1][j] = min(dp[i][j] + 1, dp[i-1][j]);

            if (a[j+1] == a[j])
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
            else
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);

            if(a[i-1] == a[j+1])
                dp[i-1][j+1] = min(dp[i-1][j+1], dp[i][j] + 1);
        }
    }
    // for(auto& it : dp[1])
    //     cout << it << " : ";
    // cout << endl;
    cout << dp[1][n] << endl;
    return 0;
}