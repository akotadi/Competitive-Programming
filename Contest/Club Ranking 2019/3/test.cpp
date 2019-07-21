#include <bits/stdc++.h>

using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define read(type) readNumber<type>()
#define ABS(x) ((x)<0?-(x):(x))
// Short names
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'

typedef vector<int> VI;
typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;


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

template <typename T = int> 
inline void writeNumber(T number)
{
    bool flag = false;
    if (number < 0) number *= -1, flag = true;
    // indexN = max length of the number
    int indexN = 20;
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

void solve(){
    // 
}

int main(){

    fastio;

    int n = read(), a = read();
    VI v(n);
    for(int i = 0; i < n; ++i) v[i] = read();

    if (n == 1) writeNumber(0);

    sort(all(v));

    cout << *upper_bound(all(v), 7) << endl;
    cout << (upper_bound(all(v), 7) == v.end()) << endl;
    cout << *lower_bound(all(v), 1) << endl;
    cout << (lower_bound(all(v), 1) == v.begin()) << endl;
    return 0;
}