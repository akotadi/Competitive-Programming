#include <bits/stdc++.h>

using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define read(type) readNumber<type>()
#define GMOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
// Short names
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'

typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;

template<typename T = int> T EXP(T n, T e, T m){T ans=1;while(e){if(e&1)ans=GMOD(ans*n,m);n=GMOD(n*n,m);n>>=1;}return ans;}

/******   Template of Fast I/O Methods   *********/

template <typename T = int>  
inline T readNumber() {
    T number = 0, numberSign = 1;
    // getchar_unlocked fast than getchar but not always allowed
    // char currentChar = getchar_unlocked();
    char currentChar = getchar();
 
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

/********   Main part of the program   ********/

#define MAXM 10000

int main(){

    fastio;

    int t = read();
    while(t--){
        int n = read(), m = read(), index = 1001;
        vector<int> a(n, 0);
        for(int i = 0; i < n; ++i) a[i] = read(), index = min(index, (a[i] > -1)?i:1001);
        if (index == n-1)
        {
            n--;
            while(n--){
                a[n] = GMOD(a[n+1] - 1, m);
            }
        }else if (index == 0)
        {
            while(--n){
                if(a[++index] == -1) a[index] = GMOD(a[index - 1] + 1, m);
            }
        }else{
            for(int i = index-1; i >= 0; --i){
                a[i] = GMOD(a[i+1] - 1, m);
            }
            while(++index < n){
                if(a[index] == -1) a[index] = GMOD(a[index - 1] + 1, m);
            }
        }
        for(auto i : a) cout << i << " ";
        cout << endl;
    }
    return 0;
}