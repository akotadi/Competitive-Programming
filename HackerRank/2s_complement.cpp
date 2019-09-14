#include<bits/stdc++.h>
using namespace std;

uint64_t maxRange = 0;

int64_t countCol(int64_t a, int col) {
    return ((int64_t)((a + 1LL) / (1LL << col)))*(1LL << (col - 1)) + max((int64_t)0, (int64_t)(((a + 1LL) % (1LL << col)) - (1LL << (col - 1LL))));
}

int64_t sumcount(int64_t a) {
    uint64_t b = (uint64_t)a;
    int64_t ans = 0LL;
    int col = 1;
    while (b) {
        b >>= 1;
        ans += countCol(a, col++);
    }
    return ans;
}

uint64_t solution(int32_t a, int32_t b) {
    int64_t aux1 = (uint32_t)(a), aux2 = (uint32_t)b;
    uint64_t ans = 0LL;

    if (a < 0L && b >= 0L) ans = maxRange - sumcount(aux1 - 1LL) + sumcount(aux2);
    else if (a < 0L && b < 0L) ans = sumcount(aux2) - sumcount(aux1 - 1);
    else if (a == 0L && b > 0L) ans = sumcount(aux2) - sumcount(aux1);
    else ans = sumcount(aux2) - sumcount(aux1 - 1);

    return ans;
}

int main() {
    uint32_t aux = (0-1);
    maxRange = sumcount((int64_t)aux);
    int t = 0;
    cin >> t;
    while(t--){
        int32_t a, b;
        cin >> a >> b;
        cout << solution(a, b) << endl;
    }
    return 0;
}