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




/********   Main part of the program   ********/

#define MAXN 10005
#define SIZE 1000001

void solve() {
    int m, n;

    while (cin >> m >> n) {
        int result = 0;

        for (int i = 0; i < m; ++i) {
            int aux;
            cin >> aux;
            result ^= aux;
        }

        cout << ((result) ? ("Vida") : ("Andrea")) << endl;
    }
}

int main() {
    solve();
    return 0;
}