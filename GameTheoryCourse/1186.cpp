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

void solve(const int &num) {
    int n;
    cin >> n;
    int result = 0;
    vector<int> white;

    for (int i = 0; i < n; ++i) {
        int aux;
        cin >> aux;
        white.emplace_back(aux);
    }

    for (int i = 0; i < n; ++i) {
        int aux;
        cin >> aux;
        result ^= aux - white[i] - 1;
    }

    cout << "Case " << num + 1 << ": " << ((result) ? ("white") : ("black")) <<
         " wins" << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        solve(i);

    return 0;
}