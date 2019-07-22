/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)
 */



int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    
    if(n == 0) return -1;
    if(n == 1) return 0;
    
    vector< pair<int, int> > a;
    for(int i = 0; i < n; i++) a.emplace_back(make_pair(A[i], i));
    
    sort(a.rbegin(), a.rend());
    
    int result = 0, current = a[0].second;
    for(int i = 1; i < n; i++){
        result = max(result, current - a[i].second);
        current = max(current, a[i].second);
    }
    
    return result;
}
