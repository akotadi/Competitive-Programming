/*
 * Copyright (c) 2019 ManuelCH.
 *
 * This file is part of Interview-solutions 
 * (see https://github.com/akotadi).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        return maxSubArrayUtil(nums, 0, n-1).largestSum;
    }
private:
    typedef struct valuesDivide {
        int leftMax, largestSum, rightMax, totalSum;
        valuesDivide(int l, int m, int r, int s):leftMax(l), largestSum(m), rightMax(r), totalSum(s){}
    } valuesDivide;
    
    valuesDivide maxSubArrayUtil(vector<int> &nums, int left, int right){
        if(left >= right) return valuesDivide(nums[left], nums[left], nums[left], nums[left]);
        
        int mid = left + (right - left) / 2;
        valuesDivide v1 = maxSubArrayUtil(nums, left, mid), v2 = maxSubArrayUtil(nums, mid + 1, right);
        int l, m, r, s;
        l = max(v1.leftMax, v1.totalSum + v2.leftMax);
        m = max(v1.rightMax + v2.leftMax, max(v1.largestSum, v2.largestSum));
        r = max(v2.rightMax, v1.rightMax + v2.totalSum);
        s = v1.totalSum + v2.totalSum;
        return valuesDivide(l, m, r, s);
    }
};