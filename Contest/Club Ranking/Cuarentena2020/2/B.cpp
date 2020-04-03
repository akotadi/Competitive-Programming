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

#define MAXN 105
#define SIZE 1000001

int n, k;
VVI dp(MAXN, VI(MAXN,-1));

VI a(MAXN);

int frequency(int index, vector<unordered_map<int,int>> &check){
    PII m_f = {-1,-1}, l_f ={-1,200};

    for(const auto &p : check[index]){
        if(p.se == m_f.se && p.fi > m_f.fi)
            m_f = p;
        else if(p.se > m_f.se)
            m_f = p;

        if(p.se == l_f.se && p.fi < l_f.fi)
            l_f = p;
        else if(p.se < l_f.se)
            l_f = p;
    }

    return m_f.fi - l_f.fi;
}

int recursive(int index, int bars, vector<unordered_map<int,int>> check){
    if(bars > k)
        return INT_MIN;
    if(bars == k || index == n)
        return frequency(k, check);

    int result = frequency(k, check);
    PII m_f = {-1,-1}, l_f ={-1,200};
    
    for(int i = index; i < n; i++){
        check[bars][a[i]]++;

        if(check[bars][a[i]] == m_f.se && a[i] > m_f.fi)
            m_f = {a[i],check[bars][a[i]]};
        else if(check[bars][a[i]] > m_f.se)
            m_f = {a[i],check[bars][a[i]]};

        if(check[bars][a[i]] == l_f.se && a[i] < l_f.fi)
            l_f = {a[i],check[bars][a[i]]};
        else if(check[bars][a[i]] < l_f.se)
            l_f = {a[i],check[bars][a[i]]};

        check[k][a[i]]--;
        if(check[k][a[i]] == 0)
            check[k].erase(a[i]);
        result = max(result, (m_f.fi - l_f.fi) + recursive(i+1, bars+1, check));
    }

    return result;
}

void solve(){
    n = read(); 
    k = read();
    k--;
    vector< unordered_map<int,int> > check(k+1);
    REP(i,n){
        a[i] = read();
        check[k][a[i]]++;
    }

    cout << recursive(0, 0, check) << endl;
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
    // tcsolve();
    solve();

    #ifdef DEBUG
        // cout << "Execution time : " << tick() << endl ;
        fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    #endif

    return 0;
}