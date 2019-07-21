/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.
*/



int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    if(n == 0) return 1;
    if(n == 1) return 0;
    
    int maxPlus = INT_MIN, maxMinus = INT_MIN, minPlus = INT_MAX, minMinus = INT_MAX;
    for(int i = 0; i < n; i++){
        maxPlus = max(maxPlus, A[i] + i);
        minPlus = min(minPlus, A[i] + i);
        maxMinus = max(maxMinus, A[i] - i);
        minMinus = min(minMinus, A[i] - i);
    }
    
    return max(maxPlus - minPlus, maxMinus - minMinus);
}
