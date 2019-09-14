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

/********   Main part of the program   ********/

#define MAXN 1000000

vector<pair<bool,int>> use;

bool is_number(const string& s)
{
    return (!s.empty()) && (find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end()) && ((s[0] == '0')?((stoi(s) == 0)?true:false):true);
}

bool sortbysec(const pair<string,int> &a, const pair<string,int> &b) 
{ 
    return (a.se == b.se)?(a.fi < b.fi):(a.se < b.se); 
} 

bool sortbynum(const pair<string,int> &a, const pair<string,int> &b) 
{ 
    if(is_number(a.fi) && is_number(b.fi)) return (a.se == b.se)?(a.fi < b.fi):(a.se > b.se); 
    if(is_number(a.fi)) return true;
    if(is_number(b.fi)) return false;
    return (a.se == b.se)?(a.fi < b.fi):(a.se < b.se); 
} 

void precalc(){
    // 
}

void solve(){
    // 
}

int main(){

    fastio;

    int n;
    cin >> n;
    pair<string,int> arr[n];
    use.resize(n+2,{false,0});
    int maxTest = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].fi;
        cin >> arr[i].se;
        maxTest += arr[i].se;
    }
    cout << maxTest << endl;
    int total = 0;
    for (int i = 0; i < n; ++i) (is_number(arr[i].fi))?((stoi(arr[i].fi) <= n)?(use[stoi(arr[i].fi)].fi = true, use[stoi(arr[i].fi)].se = arr[i].se, total++):0):0;
    // cout << total << endl;
    int lastSpace = n+1;
    for(int i = 0; i <= n; i++) (use[i].fi == 0)?lastSpace = i:0;
    cout << lastSpace << endl;
    for(auto& it : use) cout << it.fi << " : " << it.se << endl;
    cout << endl;
    vector<pair<string,int>> aux(arr, arr+sizeof(arr)/sizeof(pair<string,int>));
    for(auto& it : aux) cout << it.fi << " : " << it.se << endl;
    // cout << endl;
    // sort(aux.begin(), aux.end(), sortbysec);
    // for(auto& it : aux) cout << it.fi << " : " << it.se << endl;
    // cout << endl;
    // sort(aux.begin(), aux.end());
    // for(auto& it : aux) cout << it.fi << " : " << it.se << endl;
    cout << endl;
    sort(aux.begin(), aux.end(), sortbynum);
    for(auto& it : aux) cout << it.fi << " : " << it.se << endl;
        cout << endl;
    int index = 1, maxIndex = n-1;
    for (int i = 0; i < maxTest; index++)
    {
        if(use[index].fi && use[index].se) {
            i++; 
            continue;
        }
        for (int j = maxIndex; j >= 0; --j)
        {
            if(aux[j].se){
                cout << "move " << aux[j].fi << " " << index << endl;
                use[index].fi = true, use[index].se = 1;
                maxIndex = j-1;
                i++;
                if(is_number(aux[j].fi) && (stoi(aux[j].fi) <= n)) use[stoi(aux[j].fi)].fi = false, use[stoi(aux[j].fi)].se = 0;
                break;
            }
        }
    }
    cout << endl;
    for(auto& it : use) cout << it.fi << " : " << it.se << endl;
    cout << index << endl;
    maxIndex = n-1;
    cout << maxIndex << " : " << n-maxTest << endl;
    for (int i = 0; i < n - maxTest; index++)
    {
        if(use[index].fi){
            i++;
            continue;
        }
        for (int j = maxIndex; j >= 0; --j)
        {
            if(aux[j].se == 0){
                cout << "move " << aux[j].fi << " " << index << endl;
                use[index].fi = true, use[index].se = 0;
                maxIndex = j-1;
                i++;
                if(is_number(aux[j].fi) && (stoi(aux[j].fi) <= n)) use[stoi(aux[j].fi)].fi = false, use[stoi(aux[j].fi)].se = 0;
                break;
            }
        }
    }
    return 0;
}