/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*/



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool cmp(Interval a, Interval b){
     if(a.start == b.start) return a.end < b.end;
     return a.start < b.start;
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> result;
    int n = A.size();
    
    if(n == 0) return result;
    
    sort(A.begin(), A.end(), cmp);
    
    // for(auto it : A) cout << it.start << " : " << it.end << endl;
    
    Interval aux;
    int i = 0, j = 0;
    while(i < n){
        aux = A[i];
        j = i + 1;
        while(j < n){
            if(A[j].start >= aux.start && A[j].start <= aux.end){
                if(A[j].end > aux.end) aux.end = A[j].end;
                j++;
            }else break;
        }
        i = j;
        result.emplace_back(aux);
    }
    
    return result;
}
