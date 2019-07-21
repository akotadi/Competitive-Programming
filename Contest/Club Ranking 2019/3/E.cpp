#include <bits/stdc++.h>

using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define read(type) readNumber<type>()
#define ABS(x) ((x)<0?-(x):(x))
// Short names
#define all(cont) cont.begin() + 1, cont.end()
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
    VI v(n+1);
    for(int i = 1; i <= n; ++i) v[i] = read();

    sort(all(v));

    if (n == 1) writeNumber(0);
    else{
        int resultUp = 0, resultDown = 0;
        if(a<=v[2])
            resultUp=abs(v[n]-a);
        else if(a>=v[n])
            resultUp=abs(v[2]-a);
        else
            resultUp=min(abs(v[2]-a)+abs(v[2]-v[n]),abs(v[n]-a)+abs(v[2]-v[n]));
     
        if(a<=v[1])
            resultDown=abs(v[n-1]-a);
        else if(a>=v[n-1])
            resultDown=abs(v[1]-a);
        else
            resultDown=min(abs(v[1]-a)+abs(v[1]-v[n-1]),abs(v[n-1]-a)+abs(v[1]-v[n-1]));
        writeNumber(min(resultUp, resultDown));
    }
    // else if(a <= v[0]) writeNumber(abs(v[n-2] - a));
    // else if (a >= v[n-1]) writeNumber(abs(v[1] - a));
    // else if (a == v[1]) writeNumber(min(abs(a - v[0]) + abs(v[0] - v[n-2]), abs(a - v[n-2])));
    // else if (a < v[1]) writeNumber(min(abs(a - v[0]) + abs(v[0] - v[n-2]), abs(a - v[n-1])));
    // else if (a == v[n-2]) writeNumber(min(abs(a - v[n-1]) + abs(v[1] - v[n-1]), abs(a - v[1])));
    // else if (a > v[n-2]) writeNumber(min(abs(a - v[n-1]) + abs(v[1] - v[n-1]), abs(a - v[0])));
    // else writeNumber(min(abs(a - v[n-1]) + abs(v[n-1] - v[1]), abs(a - v[0]) + abs(v[0] - v[n-2])));
    return 0;
}