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

class TreeNode {
public:
    TreeNode* next[2];
    TreeNode () {next[0] = NULL; next[1] = NULL;};
};

TreeNode* buildTree(vector<Long>& nums) {
    TreeNode* root = new TreeNode(), *cur;
    Long n = nums.size();
    REP(i,n) {
        Long num = nums[i];
        cur = root;
        RREP(j,62) {
            Long index = ((num >> j) & 1ll);
            if (cur->next[index] ==  NULL)
                cur->next[index] = new TreeNode();
            cur = cur->next[index];
        }
    }
    return root;
}

Long helper(TreeNode* cur, Long num) {
    Long res = 0ll;
    RREP(i,62){
        Long index = ((num >> i) & 1ll) ? 0ll : 1ll;
        if (cur->next[index]) {
            res <<= 1ll;
            res |= 1ll;
            cur = cur->next[index];
        } else {
            res <<= 1ll;
            res |= 0ll;
            cur = cur->next[index ? 0ll : 1ll];
        }
    }
    return res;
}

void solve(){
    int n;
    cin >> n;

    vector<Long> a(n);
    REP(i,n) cin >> a[i];

    Long ans = 0;
    TreeNode* root = buildTree(a);
    
    for (auto &i : a) {
        ans = max(ans, helper(root, i));
    }
    
    cout << ans << endl;
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