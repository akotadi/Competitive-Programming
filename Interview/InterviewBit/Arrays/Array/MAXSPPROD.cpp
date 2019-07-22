/*
You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9
 */



int Solution::maxSpecialProduct(vector<int> &A) {
    int64_t aux = 0, result = 0;
    int64_t mod = 1000000007;
    stack<pair<int64_t, int64_t>> leftStack, rightStack;
    unordered_map<int64_t, int64_t> leftValues;
    for(int64_t i = 0; i < A.size(); i++){
        int64_t leftSpecialValue = 0;
        while(!leftStack.empty()){
            if(leftStack.top().first > A[i]){
                leftSpecialValue = leftStack.top().second;
                break;
            }else{
                leftStack.pop();
            }
        }
        leftValues[i] = leftSpecialValue;
        leftStack.push({A[i], i});
    }
    for(int64_t i = A.size() - 1; i >= 0; i--){
        int64_t rightSpecialValue = 0;
        while(!rightStack.empty()){
            if(rightStack.top().first > A[i]){
                rightSpecialValue = rightStack.top().second;
                break;
            }else{
                rightStack.pop();
            }
        }
        rightStack.push({A[i], i});
        aux = (rightSpecialValue * leftValues[i]);
        result = max(result, aux);
    }
    return result % mod;
}
