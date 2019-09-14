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