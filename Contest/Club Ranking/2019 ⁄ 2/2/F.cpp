#include <bits/stdc++.h>

using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define read(type) readNumber<type>()
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

void precalc(){
    // 
}

void solve(){
    // 
}

int main(){

    fastio;

    int n = read(), a = read(), b = read();
    // cout << n << " : " << a << " : " << b << endl;
    int arr[n], sum = 0;
    for (int i = 0; i < n; ++i)
    {
        arr[i] = read();
        sum += arr[i];
    }
    // cout << sum << endl;
    sort(arr+1, arr+n);
    // for(auto& it : arr) cout << it << " : ";
    // cout << endl;
    reverse(arr+1, arr+n);
    // for(auto& it : arr) cout << it << " : ";
    // cout << endl;
    int result = 0;
    for (int i = 1; i < n; ++i)
    {
        if ((arr[0]*a)/sum >= b) break;
        result++;
        sum -= arr[i];
    }
    writeNumber(result);
    return 0;
}