/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), aux = 0;
        
        if(n == 0) return n;
        if(n == 1) return (nums[0] == 0)?1:0;
        
        for(auto number : nums) 
            if(number >= n){
                aux = number;
                break;
            }
        
        if(aux == 0) return n;
        
        for(int i = 0; i < n; i++)
            aux ^= i;
        
        for(auto number : nums)
            aux ^= number;
        
        return aux;
    }
};