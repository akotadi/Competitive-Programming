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
// #include <bits/stdc++.h>

// C library to perform I/O operations (scanf, printf, getchar primmarly)
#include <cstdio>
// C++ standard I/O streams.
#include <iostream>
#include <iomanip>
// Debbuging tool in C.
#include <cassert>

// Collection of functions especially designed to be used on ranges of elements.
#include <algorithm>
// Set of functions to compute common mathematical operations and transformations.
#include <cmath>

// Data structures of STL C++.
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iterator>

// C string's with functions like strlen, strcpy, etc...
#include <cstring>
// Strings for C++
#include <string>
// Stringstreams for C++
#include <sstream>

// Used for function objects, are objects specifically designed to
// be used with a syntax similar to that of functions, ex:
// struct myclass {
//   int operator()(int a) {return a;}
// } myobject;
// int x = myobject (0);
#include <functional>
// Set of algorithms to perform certain operations on sequences of numeric values.
#include <numeric>
// Utility components, most used for pair and his operations
#include <utility>
// Defines elements with the characteristics of arithmetic types. (numeric_limits<T>)
#include <limits>
#include <climits>

// Time library for C++11.
#include <chrono>
// Introduces random number generation facilities.
#include <random>
// General purpose functions of C like atoi, stoi, rand, etc...
#include <cstdlib>
// Time functions of C like clock.
#include <ctime>



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

// Provides a random number generation based on Mersenne Twister algorithm.
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
// Use ex: int m = mt_rand();
mt19937 mt_rand(seed);

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
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())
#define bitcount(n) __builtin_popcountll(n)
#define sz(a) int((a).size())
// Numbers
#define INF (int)1e9
// #define INF 1<<30
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define GOLD ((1+sqrt(5))/2) // Golden ratio

typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;

// const double PI = acos(-1.0);
// const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
// const int MAX   = 1e5 + 5;
// const int LIM   = 3e5 + 5;
// const Double  EPS   = 1e-10;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;

template <typename T = int, typename U = int> void swapi(T *a, U *b) {(*a) ^= (*b); (*b) ^= (*a); (*a) ^= (*b);}
double tick() {static clock_t oldt, newt = clock(); double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC; oldt = newt; return diff;}
template<typename T = int> T EXP(T n, T e) {T ans = 1; while (e) {if (e & 1)ans *= n; n *= n; e >>= 1;} return ans;}
template<typename T = int> T EXP(T n, T e, T m) {T ans = 1; while (e) {if (e & 1)ans = GMOD(ans * n, m); n = GMOD(n * n, m); e >>= 1;} return ans;}
template<typename T = int> T MULT(T a, T b) {T ans = 0; if (abs(b) > abs(a))swapi<T>(a, b); if (b < 0)a *= -1, b *= -1; while (b) {if (b & 1)ans += a; b >>= 1; a += a;} return ans;}
template<typename T = int> T MULT(T a, T b, T m) {T ans = 0; a %= m; b %= m; if (abs(b) > abs(a))swapi<T>(a, b); if (b < 0)a *= -1, b *= -1; while (b) {if (b & 1)ans = (ans + a) % m; b >>= 1; a = (a + a) % m;} return ans;}
template<typename T> T extendedGCD(T a, T b, T &x, T &y) {T xx = 0, yy = 1; y = 0; x = 1; while (b) {T q = a / b, t = b; b = a % b; a = t; t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;} return a;}
template<typename T> T modInverse(T a, T n) {T x, y; T d = extendedGCD(a, n, x, y); return (d > 1 ? -1 : GMOD(x, n));}

inline string to_string(int num) {stringstream ss; ss << num; return ss.str();}

#define tcsolve() int tcs; cin >> tcs; while(tcs--) solve();


/********   Main part of the program   ********/

#define MAXN 10005
#define SIZE 10005
int mex[SIZE / 2 + 1];
bool dp[SIZE];

void solve() {
    int a, b;
    cin >> a >> b;
    cout << ((!(a & 1) || !(b & 1)) ? ("Gana el primer jugador.")
             : ("Gana el segundo jugador."))
         << endl;
}



int main() {
    // fastio;
#ifdef DEBUG
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("log.txt", "w", stderr);
#endif
    // ofstream fout("bubble.out");
    // ifstream fin("bubble.in");
    // fin >> N;
    // compile program
    tcsolve();
    // solve();
#ifdef DEBUG
    // cout << "Execution time : " << tick() << endl ;
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}