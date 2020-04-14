#include <bits/stdc++.h>

using namespace std;

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}

#define read(type) readNumber<type>()
#define prec(n,a) fixed << setprecision(n) << a
#define FORI(i, a, b, in) for (int i=a ; i<b ; i+=in)
#define RFORI(i, a, b, in) for (int i=a ; i>=b ; i-=in)
#define FOR(i, a, b) for (int i=a ; i<b ; i++)
#define RFOR(i, a, b) for (int i=a ; i>=b ; i--)
#define REP(i, b) FOR(i, 0, b)
#define RREP(i, a) RFOR(i, a, 0)
#define ABS(x) ((x)<0?-(x):(x))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR0(a) memset(a, 0, sizeof(a))
#define CLRINF(a) memset(a, 0x3f3f3f3f, sizeof(a))
#define GMOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define sz(a) int((a).size())

typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef map<int,int> MPII;
typedef set<int> SETI;

#define tcsolve() int tcs=read(int); while(tcs--) solve();

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

#define MAXN 35
#define SIZE 1000001
#define mod 1000000007

vector<int> lowestPrime;
void lowestPrimeSieve(){
    lowestPrime.resize(MAXN + 1, 1);
    lowestPrime[0] = lowestPrime[1] = 0;
    for(int i = 2; i <= MAXN; ++i) lowestPrime[i] = (i & 1 ? i : 2);
    int limit = sqrt(MAXN);
    for(int i = 3; i <= limit; i += 2)
        if(lowestPrime[i] == i)
            for(int j = i * i; j <= MAXN; j += 2 * i)
                if(lowestPrime[j] == j) lowestPrime[j] = i;
}

VI prime(MAXN+1);
void SieveOfEratosthenes() 
{ 
    for (int i = 2; i * i <= MAXN; ++i) 
    { 
        if (!prime[i]) 
            for (int j = i * 2; j <= MAXN; j += i) 
                prime[j] = i; 
    } 
  
    // Prime number will have same divisor 
    for (int i = 1; i < MAXN; ++i) 
        if (!prime[i]) 
            prime[i] = i; 
} 

void precalc(){
    lowestPrimeSieve();
    SieveOfEratosthenes();
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector< unordered_set<char> > check(m);
    char c;
    REP(i,n){
        REP(j,m){
            cin >> c;
            check[j].insert(c);
        }
    }

    Long result = 1;
    for(const auto &it : check){
        result *= it.size();
        result %= mod;
    }

    cout << result << endl;
}

int main(){

    // fastio;

    #ifdef DEBUG
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        // freopen("log.txt", "w", stderr);
    #endif

    // ofstream fout("bubble.out");
    // ifstream fin("bubble.in");
    // fin >> N;

    precalc();
    ofstream fout1("primes1.out");
    for(const auto &num : lowestPrime)
        fout1 << num << " ";
    fout1 << endl;
    ofstream fout2("primes2.out");
    for(const auto &num : prime)
        fout2 << num << " ";
    fout2 << endl;

    // compile program
    // tcsolve();
    // solve();

    #ifdef DEBUG
        // cout << "Execution time : " << tick() << endl ;
        fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    #endif

    return 0;
}