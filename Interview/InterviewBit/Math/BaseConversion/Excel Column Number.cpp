/*
Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
 */



int Solution::titleToNumber(string A) {
    uint64_t answer = 0;
    for(int i = 0; i < A.size(); i++){
        uint32_t exponent = A.size() - i - 1;
        uint64_t partial = pow(26, exponent);
        partial *= (A[i] - 'A') + 1;
        answer += partial;
    }
    return answer;
}
