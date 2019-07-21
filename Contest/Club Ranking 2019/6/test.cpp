#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MAXN 4

int main() {
    ios::sync_with_stdio(false);
    int aux = MAXN, index = 3;
    while (aux --> 0) {
        cout << aux << endl;
        index--;
    }
    cout << index << endl;
}