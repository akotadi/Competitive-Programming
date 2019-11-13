// Compilation with:
// g++ file.cpp -D<DEBUG> -o file && ./file < input > output


/********   Pragma Headers to control the compiler flags ********/

// Unroll loops is efficient for a short amount of this.
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//
// Problems with long double
// #define __USE_MINGW_ANSI_STDIO
// Avoid warning
// #define _CRT_SECURE_NO_WARNINGS


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


// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define read(type) readNumber<type>()
#define sci(t) scanf("%d",&t)
#define scl(t) scanf("%ld",&t)
#define scll(t) scanf("%lld",&t)
#define scui(t) scanf("%u",&t)
#define scul(t) scanf("%lu",&t)
#define scull(t) scanf("%llu",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define scd(t) scanf("%lf",&t)
#define pnl printf("\n")
#define prec(n,a) fixed << setprecision(n) << a
// Stringizing operator (#) - Token-pasting operator (##)
#define db(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
// Use debug("Time: %.3f\n", (double)(clock()) / CLOCKS_PER_SEC);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define Assert(x)       {if(!(x)){cerr<<"Assertion failed at line "<<__LINE__<<": "<<#x<<" = "<<(x)<<"\n";exit(1);}}
// Microiterations
#define FORI(i, a, b, in) for (int i=a ; i<b ; i+=in)
#define RFORI(i, a, b, in) for (int i=a ; i>=b ; i-=in)
#define FOR(i, a, b) for (int i=a ; i<b ; i++)
#define RFOR(i, a, b) for (int i=a ; i>=b ; i--)
#define REP(i, b) FOR(i, 0, b)
#define RREP(i, a) RFOR(i, a, 0)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define FORAUTO(a) for(auto& n : a)
// Microfunctions
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR0(a) memset(a, 0, sizeof(a))
#define CLRINF(a) memset(a, 0x3f3f3f3f, sizeof(a))
#define IN(A, B, C) assert( B <= A && A <= C)
#define GMOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
// Short names
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())
#define bitcount(n) __builtin_popcountll(n)
#define sz(a) int((a).size())

typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;



/********   Main part of the program   ********/

#define MAXN 1000005
#define SIZE 1000001

VI primes;
vector<bool> isPrime;

void primesSieve() {
    isPrime.result(MAXN, true);
    isPrime[0] = isPrime[1] = false;
    primes.pb(2);

    for (int i = 4; i < MAXN; i += 2)
        isPrime[i] = false;

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


void precalc() {
    greatestPrimeSieve();
    divisorsSieve();
}

void solve(int caseNumber) {
    int n;
    cin >> n;

    if (n < 4) {
        cout << "Case #" << caseNumber + 1 << ": 0" << endl;
        return;
    }

    int aux = n, result = 1;

    while (aux != 1) {
        int check = aux, counter = 1;

        while (aux % greatestPrime[check] == 0) {
            counter++;
            aux /= greatestPrime[check];
        }

#ifdef DEBUG
        cout << aux << " : " << result << endl;
#endif
        result *= counter;
    }

#ifdef DEBUG
    cout << result << endl;
#endif
    cout << "Case #" << caseNumber + 1 << ": " << (n - result) << endl;
}

int main() {
    //
    //
    // compile program
    precalc();
#ifdef DEBUG

    for (int i = 0; i < 40; ++i)
        cout << i << " - " << greatestPrime[i] << " : " << divisors[i] << endl;

#endif
    int tcs; cin >> tcs;

    for (int i = 0; i < tcs; ++i)
        solve(i);

    // solve();
    return 0;
}