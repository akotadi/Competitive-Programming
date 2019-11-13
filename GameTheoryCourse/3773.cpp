// Compilation with:
// g++ file.cpp -D<DEBUG> -o file && ./file < input > output


/********   Header Files ********/

// Include all the libraries
#include <bits/stdc++.h>



/********   Definitions for our program, including constants and typedef   ********/

// Replace use std:: with the standard C++.
using namespace std;

__attribute__((constructor)) void _() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
}

// static auto const fastio = [](){
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
//   return nullptr;
// }();
//

#define pb emplace_back

typedef long long int lli;
typedef vector<int> VI;

/********   Main part of the program   ********/

#define MAXN 31630
#define SIZE 1000000005

VI primes;
vector<bool> isPrime;
void primesSieve() {
#ifdef DEBUG
    cout << "s primesSieve" << endl;
#endif
    isPrime.resize(MAXN, true);
    isPrime[0] = isPrime[1] = false;
    primes.pb(2);

    for (int i = 4; i < MAXN; i += 2) isPrime[i] = false;

    int limit = sqrt(MAXN);

    for (int i = 3; i < MAXN; i += 2) {
        if (isPrime[i]) {
            primes.pb(i);

            if (i <= limit) {
                for (int j = i * i; j < MAXN; j += (2 * i))
                    isPrime[j] = false;
            }
        }
    }
}

VI primeFactors;
void primeFactorsSieve() {
#ifdef DEBUG
    cout << "s primeFactorsSieve" << endl;

    for (const auto &num : primes)
        cout << num << " ";

    cout << endl;
#endif
    primeFactors.resize(MAXN, 0);

    for (const auto &num : primes) {
        for (int i = num; i < MAXN; i += num) {
            if (i * i > MAXN)
                break;

            primeFactors[i]++;
        }
    }
}

void precalc() {
    primesSieve();
    primeFactorsSieve();
#ifdef DEBUG
    cout << "s primeFactorsSieve" << endl;

    for (int i = 0; i < 20; ++i)
        cout << i << " : " << primeFactors[i] << endl;

#endif
}

void solve() {
    int n;
    cin >> n;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        int aux;
        cin >> aux;
        result ^= primeFactors[aux];
    }

    cout << ((result) ? ("Poo") : ("Mak")) << endl;
}

int main() {
    precalc();
    int n;
    cin >> n;

    while (n--) solve();

    return 0;
}