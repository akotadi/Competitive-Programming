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
    string s;
    cin >> s;
    int result = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.')
            break;
        else if (i + 1 == s.size()) {
            cout << "Rabbit" << endl;
            return;
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '#')
            break;
        else if (i + 1 == s.size()) {
            cout << "Rabbit" << endl;
            return;
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        int partial = 0;

        while (i < s.size() && s[i] == '.') {
            partial++;
            i++;
        }

#ifdef DEBUG
        cout << partial << endl;
#endif
        result ^= partial;
    }

#ifdef DEBUG
    cout << result << endl;
#endif
    cout << ((result) ? ("Cat") : ("Rabbit")) << endl;
}

int main() {
    solve();
    return 0;
}