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

#define tcsolve() int tcs=readNumber(); while(tcs--) solve();

typedef vector<int> VI;
typedef vector<VI> VVI;

/******   Template of Fast I/O Methods   *********/

template <typename T = int>  
inline T readNumber() {
    T number = 0, numberSign = 1;
    // getchar_unlocked fast than getchar but not always allowed
    // char currentChar = getchar_unlocked();
    register char currentChar = getchar();
 
    while ((currentChar < '0' || currentChar > '9') && currentChar != EOF) {
        if (currentChar == '-')  numberSign = -1;
        // currentChar = getchar_unlocked();
        currentChar = getchar();
    }

    while (currentChar >= '0' && currentChar <= '9') {
        number = (number << 3) + (number << 1) + (currentChar & 15);
        // currentChar = getchar_unlocked();
        currentChar = getchar();
    }

    return number * numberSign;
}

template <typename T = int> 
inline void writeNumber(T number)
{
    bool flag = false;
    if (number < 0) number *= -1, flag = true;
    // indexN = max length of the number
    register int indexN = 20;
    char buffer[21];
    // buffer[10] = 0;
    buffer[20] = '\n';

    do{
        buffer[--indexN] = number % 10 + '0';
        number /= 10;
    }while(number);

    if (flag) putchar('-');
    
    do{
        // putchar_unlocked fast than putchar but not always allowed
        // putchar_unlocked(buffer[indexN]);
        putchar(buffer[indexN]);
    } while (buffer[indexN++] != '\n');
}

/********   Main part of the program   ********/

void precalc(){
    // 
}

int n;
VVI a;

int maxValue(int x, int y){
    int val1 = ((x+1 >= 0 && x+1 < n) && (y >= 0 && y < n))?(a[x+1][y]):(0);
    int val2 = ((x+1 >= 0 && x+1 < n) && (y-1 >= 0 && y-1 < n))?(a[x+1][y-1]):(0);
    int val3 = ((x+1 >= 0 && x+1 < n) && (y+1 >= 0 && y+1 < n))?(a[x+1][y+1]):(0);

    return max(val1, max(val2, val3));
}

void solve(){
    // 
    for(auto& row: a)
        row.clear();
    a.clear();
    n = readNumber();
    a.resize(n, VI(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = readNumber();

    for (int i = n-2; i >= 0; --i)
        for (int j = 0; j < n; ++j)
            a[i][j] += maxValue(i, j);

    int result = 0;
    for(auto& num : a[0]) result = max(result, num);

    writeNumber(result);
}

int main(){

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
        fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    #endif

    return 0;
}