/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.
*/



int Solution::maxSubArray(const vector<int> &A) {
    int result = 0, aux = 0, maxNegative = 0;
    bool flag = false;
    for(auto number : A){
        if(number <= 0 && flag){
            maxNegative = max(maxNegative, number);
        }else if(number <= 0) {
            maxNegative = number; 
            flag = true;
        }
        if(aux + number >= 0){
            aux += number;
            result = max(result, aux);
        }else{
            aux = 0;
        }
    }
    return (result == 0)?maxNegative:result;
}
