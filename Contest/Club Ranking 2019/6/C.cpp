#include <bits/stdc++.h>

using namespace std;

// Short reading macros
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// Short names
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define endl '\n'

/********   Main part of the program   ********/

#define MAXM 1000

int main(){
    ios::sync_with_stdio(false);

    int aux = 0, counter = MAXM;

    while (aux == 0 && counter --> 0) {
        cout << "-" << endl;
        cin >> aux;
    }
    if (aux)
    {
        cout << "-" << endl;
        cin >> aux;
        cout << "-" << endl;
        cin >> aux;
        cout << "+" << endl;
        cin >> aux;
        if (aux)
        {
            cout << "! good" << endl;
        }else{
            cout << "! ugly" << endl;
        }
    }else{
        counter = 2 * MAXM;
        while(counter --> 0)
        {
            cout << "+" << endl;
            cin >> aux;
        }
        counter = MAXM;
        while (aux == 0 && counter --> 0) {
            cout << "+" << endl;
            cin >> aux;
        }
        if (aux)
        {
            cout << "+" << endl;
            cin >> aux;
            cout << "+" << endl;
            cin >> aux;
            cout << "-" << endl;
            cin >> aux;
            if (aux)
            {
                cout << "! bad" << endl;
            }else{
                cout << "! ugly" << endl;
            }
        }else{
            cout << "! ugly" << endl;
        }

    }

    return 0;
}