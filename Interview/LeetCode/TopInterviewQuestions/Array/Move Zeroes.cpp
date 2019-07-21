/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        
        int n = nums.size();
        for(int i = 0, j = 1; i < n && j < n; i++){
            if(nums[i] == 0){
                j = max(j, i + 1);
                while(j < n){
                    if(nums[j]){
                        swapi(nums[i], nums[j++]); 
                        break;
                    }else j++;
                } 
            }
        }
        
        return;
    }
private:
    void swapi(int &a, int &b){
        a ^= b;
        b ^= a;
        a ^= b;
        
        return;
    }
};