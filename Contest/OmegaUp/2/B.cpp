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

#define MAXN 30005
#define SIZE 1000001
using ld = long double;
ld eps = 1e-9, inf = numeric_limits<ld>::max();
// For use with integers, just set eps=0 and everything remains the same
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

struct point{
    ld x, y;
    point(): x(0), y(0){}
    point(ld x, ld y): x(x), y(y){}

    point operator+(const point & p) const{return point(x + p.x, y + p.y);}
    point operator-(const point & p) const{return point(x - p.x, y - p.y);}
    point operator*(const ld & k) const{return point(x * k, y * k);}
    point operator/(const ld & k) const{return point(x / k, y / k);}

    point operator+=(const point & p){*this = *this + p; return *this;}
    point operator-=(const point & p){*this = *this - p; return *this;}
    point operator*=(const ld & p){*this = *this * p; return *this;}
    point operator/=(const ld & p){*this = *this / p; return *this;}

    point rotate(const ld & angle) const{
        return point(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
    }
    point perp() const{return point(-y, x);}

    ld dot(const point & p) const{return x * p.x + y * p.y;}
    ld cross(const point & p) const{return x * p.y - y * p.x;}
    ld norm() const{return x * x + y * y;}
    ld length() const{return sqrtl(x * x + y * y);}
    point unit() const{return (*this) / length();}

    bool operator==(const point & p) const{return eq(x, p.x) && eq(y, p.y);}
    bool operator!=(const point & p) const{return !(*this == p);}
    bool operator<(const point & p) const{return le(x, p.x) || (eq(x, p.x) && le(y, p.y));}
    bool operator>(const point & p) const{return ge(x, p.x) || (eq(x, p.x) && ge(y, p.y));}
    bool half(const point & p) const{return le(p.cross(*this), 0) || (eq(p.cross(*this), 0) && le(p.dot(*this), 0));}
};

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}

point intersectLines(const point & a1, const point & v1, const point & a2, const point & v2){
    //lines a1+tv1, a2+tv2
    //assuming that they intersect
    ld det = v1.cross(v2);
    return a1 + v1 * ((a2 - a1).cross(v2) / det);
}

pair<point, ld> getCircle(const point & m, const point & n, const point & p){
    //find circle that passes through points p, q, r
    point c = intersectLines((n + m) / 2, (n - m).perp(), (p + n) / 2, (p - n).perp());
    ld r = (c - m).length();
    return {c, r};
}

pair<point, ld> mec2(vector<point> & S, const point & a, const point & b, int n){
    ld hi = inf, lo = -hi;
    for(int i = 0; i < n; ++i){
        ld si = (b - a).cross(S[i] - a);
        if(eq(si, 0)) continue;
        point m = getCircle(a, b, S[i]).first;
        ld cr = (b - a).cross(m - a);
        if(le(si, 0)) hi = min(hi, cr);
        else lo = max(lo, cr);
    }
    ld v = (ge(lo, 0) ? lo : le(hi, 0) ? hi : 0);
    point c = (a + b) / 2 + (b - a).perp() * v / (b - a).norm();
    return {c, (a - c).norm()};
}

pair<point, ld> mec(vector<point> & S, const point & a, int n){
    random_shuffle(S.begin(), S.begin() + n);
    point b = S[0], c = (a + b) / 2;
    ld r = (a - c).norm();
    for(int i = 1; i < n; ++i){
        if(ge((S[i] - c).norm(), r)){
            tie(c, r) = (n == S.size() ? mec(S, S[i], i) : mec2(S, a, S[i], i));
        }
    }
    return {c, r};
}

pair<point, ld> smallestEnclosingCircle(vector<point> S){
    assert(!S.empty());
    auto r = mec(S, S[0], S.size());
    return {r.first, sqrt(r.second)};
}

void precalc(){

}

void solve(){
    int n, m, l;
    cin >> n >> m >> l;
    vector<point> a;
    REP(i,l){
        ld x, y;
        cin >> x >> y;
        a.pb(point(x,y));
    }
    int q;
    cin >> q;
    REP(i,q){
        int k;
        cin >> k;
        vector<point> b;
        REP(j,k){
            int aux;
            cin >> aux;
            b.pb(a[aux-1]);
        }
        cout << prec(10,smallestEnclosingCircle(b).se) << endl;
    }
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

    // compile program
    // tcsolve();
    solve();

    #ifdef DEBUG
        // cout << "Execution time : " << tick() << endl ;
        fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    #endif

    return 0;
}