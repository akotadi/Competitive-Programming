//#pragma GCC optimize("Ofast, unroll-loops")
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <cassert>
#include <functional>
#include <queue>
#include <numeric>
#include <bitset>
#include <iterator>

using namespace std;

mt19937 gen(time(NULL));
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define forn(i, n) for (int i = 0; i < n; i++)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define mp make_pair
#define endl '\n'

typedef long long ll;

template <typename T = int>  
inline T read() {
    T number = 0, numberSign = 1;
    char currentChar = getchar();
 
    while (currentChar < '0' or currentChar > '9') {
        if (currentChar == '-')  numberSign = -1;
        currentChar = getchar();
    }

    while (currentChar >= '0' and currentChar <= '9') {
        number = (number << 3) + (number << 1) + (currentChar - '0');
        currentChar = getchar();
    }

    return number * numberSign;
}



int main(){
    optimizar_io

    int n = read();
    int result = 1, lastA = 0, lastB = 0, newA = 0, newB = 0;
    for (int i = 1; i <= n; ++i)
    {
        newA = read();
        newB = read();
        if (lastA == newA && lastB == newB){
            continue;
        }
        else if (lastA > lastB)
        {
            if(newA > newB){
                if( newB >= lastA){
                    result += newB - lastA + 1;
                }
            }
            else {
                result += newA - lastA + 1;
            }
        }else if (lastA < lastB)
        {
            if(newA < newB){
                if( newA >= lastB){
                    result += newA - lastB + 1;
                }
            }
            else {
                result += newB - lastB + 1;
            }
        }else if (lastA == lastB){
            result += min(newA, newB) - lastA;
        }
        lastA = newA;
        lastB = newB;
    }
    cout << result << endl;
    return 0;
}