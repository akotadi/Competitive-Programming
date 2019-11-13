#include <bits/stdc++.h>

using namespace std;

deque<char> check;
int matrix[8][7];
int da[26];
string p;

const auto m = 4;
const auto INF = 15;

int min(int a, int b, int c, int d) {
    int result;
    result = min(a, b);
    result = min(result, c);
    result = min(result, d);
    return result;
}

int damerauLevenshteinDistance(int n) {

    memset(matrix, 0, sizeof(matrix));
    matrix[0][0] = INF;

    for (int i = 0; i < n + 1; i++) {
        matrix[i + 1][1] = i;
        matrix[i + 1][0] = INF;
    }

    for (int j = 0; j < m + 1; j++) {
        matrix[1][j + 1] = j;
        matrix[0][j + 1] = INF;
    }

    memset(da, 0, sizeof(da));
    char cs, ct;
    int cost, lastCol, lastRow;

    for (int row = 1; row <= n; row++) {
        cs = check[row - 1];
        lastCol = 0;

        for (int col = 1; col <= m; col++) {
            ct = p[col - 1];
            lastRow = da[ct - 'a'];
            cost = (cs == ct) ? (0) : (1);
            matrix[row + 1][col + 1] = min(
                                           matrix[row][col + 1] + 1,            // insertion
                                           matrix[row + 1][col] + 1,            // deletion
                                           matrix[row][col] + cost,             // substitution
                                           matrix[lastRow][lastCol]             // transposition
                                           + (row - lastRow - 1) + 1
                                           + (col - lastCol - 1)
                                       );
            lastCol = (cost == 0) ? (col) : (lastCol);
        }

        da[cs - 'a'] = row;
    }

    return matrix[n + 1][m + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    p = "meow";
    if(s.find(p) != string::npos){
    	cout << 0 << endl;
	return 0;
    }
    int result = 4;
	
    check.clear();
    int aux = 5;
    while(aux--) check.push_back('x');
    for (int i = 0; i < s.size() + 4; i++) {
	if(result == 1) break;
        check.push_back((i < s.size()) ? s[i] : 'x');
	check.pop_front();
	for(int j = 1; j < 6; j++)
		result = min(result, damerauLevenshteinDistance(j));
    }

    cout << result << endl;

    return 0;
}
