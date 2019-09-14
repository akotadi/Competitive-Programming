#include <bits/stdc++.h>

using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define read(type) readNumber<type>()
// Short names
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'

typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef long long int Long;
typedef unsigned long long int  uLong;
typedef long double Double;

/********   Main part of the program   ********/

#define MAXM 10000

int main(){

    fastio;

    int n;
    cin >> n;
    VII a(n);
    unordered_map<int,int> average;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].fi;
        a[i].se = i+1;
        average[a[i].fi]++;
    }
    int aux = (*average.begin()).fi;
    for(auto it : average) aux = (average[aux] < it.second)?it.fi:aux;
    sort(all(a));
    int check = (((*(a.end() - 1)).fi + (*(a.begin())).fi)) / 2;
    if((((*(a.begin())).fi + (*(a.end() - 1)).fi) & 1) || (n > 2 && ((*(a.begin() + 1)).fi != (*(a.end() - 2)).fi || (*(a.begin() + 1)).fi != check))){
        cout << "Unrecoverable configuration." << endl;
    }
    else if ((*(a.begin())).fi == (*(a.end() - 1)).fi){
        cout << "Exemplary pages." << endl;
    }
    else{
        int result = ((*(a.end() - 1)).fi - (*(a.begin())).fi) / 2;
        cout << result << " ml. from cup #" << (*(a.begin())).se << " to cup #" << (*(a.end() - 1)).se << "." << endl;
    }
    return 0;
}