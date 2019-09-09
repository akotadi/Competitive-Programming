class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (n == 0) return true;
        
        // isAscendent: 0 - false, 1 - true, 2 - undefined;
        int8_t isAscendent = 2;
        for (int i = 1; i < n; i++) {
            // If equals, doesn't matter
            if (A[i] == A[i-1]) 
                continue;
            // If flag undefined, define it
            else if (isAscendent == 2) {
                if(A[i] < A[i-1]) 
                    isAscendent = 0;
                else 
                    isAscendent = 1;
            }
            else {
                if (isAscendent) {
                    if(A[i] > A[i-1]) 
                        continue;
                    else 
                        return false;
                } else {
                    if(A[i] < A[i-1]) 
                        continue;
                    else
                        return false;
                }
            }
            
        }
        
        return true;
    }
};
