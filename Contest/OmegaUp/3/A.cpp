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

#define tcsolve() int tcs; cin >> tcs; while(tcs--) solve();

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
        currentChar = getchar_unlocked();
        // currentChar = getchar();
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
        putchar_unlocked(buffer[indexN]);
        // putchar(buffer[indexN]);
    } while (buffer[indexN++] != '\n');
}

#define MAXN 100000005
#define SIZE 1000001

void precalc(){
    
}

void solve(){
    int n;
    cin >> n;

    VI a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 23, 25, 26, 28, 29, 33, 36, 39, 40, 44, 45, 46, 47, 48, 49, 50, 55, 56, 58, 59, 66, 69, 70, 77, 78, 79, 80, 88, 89, 99, 100, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 122, 123, 125, 126, 128, 129, 133, 136, 139, 140, 144, 145, 146, 147, 148, 149, 150, 155, 156, 158, 159, 166, 169, 170, 177, 178, 179, 180, 188, 189, 199, 200, 220, 222, 223, 225, 226, 228, 229, 233, 236, 239, 250, 255, 256, 258, 259, 266, 269, 280, 288, 289, 299, 333, 336, 339, 366, 369, 399, 400, 440, 444, 445, 446, 447, 448, 449, 450, 455, 456, 458, 459, 466, 469, 470, 477, 478, 479, 480, 488, 489, 499, 500, 550, 555, 556, 558, 559, 566, 569, 580, 588, 589, 599, 666, 669, 699, 700, 770, 777, 778, 779, 780, 788, 789, 799, 800, 880, 888, 889, 899, 999};
    auto it = lower_bound (a.begin(), a.end(), n);
    auto it2 = lower_bound (a.begin(), a.end(), n);
    --it2;
    if(abs((*it) - n) < abs((*it2) - n))
        cout << (*it) << endl;
    else 
        cout << (*it2) << endl;
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

    // compile program
    tcsolve();
    // solve();

    #ifdef DEBUG
        // cout << "Execution time : " << tick() << endl ;
        fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    #endif

    return 0;
}