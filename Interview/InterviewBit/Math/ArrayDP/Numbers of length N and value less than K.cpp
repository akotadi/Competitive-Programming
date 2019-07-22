/*
Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.

 NOTE: All numbers can only have digits from the given set. 
Examples:

	Input:
	  0 1 5  
	  1  
	  2  
	Output:  
	  2 (0 and 1 are possible)  

	Input:
	  0 1 2 5  
	  2  
	  21  
	Output:
	  5 (10, 11, 12, 15, 20 are possible)
Constraints:

    1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9
 */



int Solution::solve(vector<int> &A, int B, int C) {
    bool flag = (A[0] == 0)?true:false;
    uint64_t answer = 0;
    string s = to_string(C);
    if(B > s.size() || A.size() == 0) return 0;
    
    if(B < s.size()) {
        if(A[0] == 0 && B != 1)
            return (A.size() - 1) * pow(A.size(), B - 1);
        else 
            return pow(A.size(), B);
    }
    if(B == 1){
        return lower_bound(A.begin(), A.end(), (s[0] - '0')) - A.begin();
    }
    
    else {
        int dp[B + 1], lower[11];
        
        for(int i = 0; i <= B; i++)
            dp[i] = 0;
        for(int i = 0; i <= 10; i++)
            lower[i] = 0;
        for(int i = 0; i < A.size(); i++)
            lower[A[i] + 1] = 1;
        
        for(int i = 1; i <= 10; i++)
            lower[i] += lower[i-1]; 
        
        bool flag = true;
        dp[0] = 0;
        
        for(int i = 1; i <= B; i++) {
            d2 = lower[digit[i-1]];
            dp[i] = dp[i-1] * A.size();
            
            if(i == 1 &&  A[0] == 0 && B != 1)
            d2 = d2 - 1;
            
            if(flag)
                dp[i] += d2;
            flag = flag & (lower[digit[i-1] + 1] == lower[digit[i-1]] + 1);
        }
        return dp[B];                   
    } 
  
    return 0;
}
