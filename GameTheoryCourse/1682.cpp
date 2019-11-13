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
    int m, n;
    cin >> n >> m;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        int partial = 0;

        for (int j = 0; j < m; ++j) {
            int aux;
            cin >> aux;
            partial += aux;
        }

        result ^= partial;
    }

    cout << "Case " << num + 1 << ": " << ((result) ? ("Alice") : ("Bob")) << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        solve(i);

    return 0;
}


gy[1] = 1;
gy[2] = 2;
gy[3] = 3;

for (int i = 4; i < MN; ++i) {
    memset(mex, 0, sizeof mex);

    for (int k = 1; k < 4; ++k) {
        for (int j = k - 1; j + k < i; ++j) {
            int cur = gy[j - k + 1] ^ gy[i - j - 1];
            mex[cur] = 1;
        }
    }

    for (int j = 0; j < MN; ++j) {
        if (!mex[j]) {
            gy[i] = j;
            break;
        }
    }
}

int tc; cin >> tc;

while (tc--) {
    int n; cin >> n;
    int ans = 0, t;

    while (n--) {
        cin >> t;
        ans ^= gy[t];
    }

    puts(ans == 0 ? "SLAVKO" : "MIRKO");
}

return 0;