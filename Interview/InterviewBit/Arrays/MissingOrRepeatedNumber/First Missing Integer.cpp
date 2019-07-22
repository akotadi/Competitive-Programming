/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
 */



int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    if(n == 0) return 1;
    
    // Iterate over the array
    for(int i = 0; i < n; i++){
        // Swap the number if is in the range [1, n+1] to his right place
        if(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]){
            swap(A[i], A[A[i] - 1]);
            i--;
        }
    }
    
    // The first possible answer is 1
    int result = 1;
    while(result <= n){
        // If the place isn't equal to the number, there is the answer
        if(A[result - 1] != result) return result;
        result++;
    }
    
    return result;
}
