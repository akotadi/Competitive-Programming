#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAXN ((1 << 10))
#define INF (1<<30)

typedef long long int lli;

typedef pair<int, int> Factor;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, cub[MAXN + 1];
int n;

vector< vector<int> > save;

int PrimeFactors(lli a) {
    int counter = 0, result = 0;

    while (!(a & 1)) ++counter, a >>= 1;

    if (counter & 1) result |= 1;

    for (int i = 1; i <= 9; ++i) {
        counter = 0;

        while (!(a % primes[i])) ++counter, a /= primes[i];

        if (counter & 1) result |= (1 << i);
    }

    return result;
}

int dp(int index, int msk) {
    if (index == MAXN) return (msk == 0) ? (0) : (-(INF));

    if (save[index][msk] == -1) {
        int result = 0;

        if (cub[index] == 0) result = dp(index + 1, msk);
        else if (cub[index] & 1) result = max(cub[index] + dp(index + 1,
                                                  msk ^ index), cub[index] - 1 + dp(index + 1, msk));
        else result = max(cub[index] + dp(index + 1, msk),
                              cub[index] - 1 + dp(index + 1, msk ^ index));

        save[index][msk] = result;
    }

    return save[index][msk];
}

int main() {
    fastio;
    cin >> n;
    vector<lli> a(n);

    for (auto &num : a) cin >> num;

    memset(cub, 0, sizeof(cub));
    save.assign(MAXN + 5, vector<int>(MAXN + 5, -1));

    for (const auto &num : a) cub[PrimeFactors(num)]++;

    cout << dp(0, 0) << endl;
    return 0;
}
