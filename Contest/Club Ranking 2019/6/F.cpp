#include <bits/stdc++.h>

using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define read(type) readNumber<type>()
#define GMOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
// Short names
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'

typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;

template<typename T = int> T EXP(T n, T e, T m){
    T ans=1;
    while(e){
        if(e&1)ans=GMOD(ans*n,m);
        n=GMOD(n*n,m);
        e>>=1;
    }
    return ans;
}


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

#define MAXN 10010

vector<bool> isPrime;
void calculatePrimes(){
    isPrime.resize(MAXN, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= MAXN; i++)
    {
        if(isPrime[i] == false) continue;
        for(int j = 2; j*i <= MAXN; j++)
            isPrime[j*i] = false;
    }
}

int main(){

    fastio;

    calculatePrimes();

    int t = read();
    int index = 1;
    while(t--){
        int n = read();
        cout << "Case #" << index++ << ": ";
        if(n == 1) cout << 1 << endl;
        else if(isPrime[n]) cout << GMOD(EXP<Long>(2, n-1, n), n) << endl;
        else cout << GMOD((n-1) * (n-1), n) << endl;
    }
    return 0;
}