#include <bits/stdc++.h>

using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define read(type) readNumber<type>()
#define prec(n,a) fixed << setprecision(n) << a
// Short names
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'

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

int main(){

    fastio;

    string s;
    cin >> s;
    float p, average = 0.0;
    cin >> p;
    for(auto& c : s) average += (c == '1')?1.0:(c == '?')?p:0.0;
    cout << prec(5, average / s.size()) << endl;
    return 0;
}