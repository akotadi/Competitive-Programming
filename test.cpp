#include <iostream>

using namespace std;

template<typename T = int> T MULT(T a, T b){
    T ans = 0;
    if (abs(b) > abs(a)) swap(a, b);
    if (b < 0) a *= -1, b *= -1;
    while(b){
        if (b & 1) ans = (ans + a);
        b >>= 1;
        a = (a+a);
    }
    return ans;
}

int main (){
    cout << (0x3f3f3f3f) << endl;
    cout << (1<<30) << endl;
    cout << (int)(1e9) << endl;
    return 0;
}
