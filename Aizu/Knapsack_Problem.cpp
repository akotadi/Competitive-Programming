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

// __attribute__((constructor)) void _() {
//   std::ios::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
//   std::cerr.tie(nullptr);
// }

static auto const fastio = [](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

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

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;



/********   Main part of the program   ********/

#define MAXN 110
#define MAXW 10010

VI dp;

void precalc(){
    // 
}

void solve(){
    // 
    int n, w;
    cin >> n >> w;
    dp.resize(MAXW, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        int value, weight;
        cin >> value >> weight;
        for (int j = weight; j <= w; ++j)
        {
            if(dp[j - weight] != -1) dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }
    cout << (*max_element(dp.begin(), dp.end())) << endl;;
}

int main(){

    // compile program
    // tcsolve();
    solve();

    return 0;
}