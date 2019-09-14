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
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        
        int left = 0, right = n-1;
        if (nums[left] > nums[right]) {
            int start = left, end = right, mid;
            while(start <= end) {
                mid = start + ((end - start) >> 1);
                if (nums[mid] < nums[(mid+1)%n] && nums[mid] < nums[((mid-1)+n)%n]) break;
                else if (nums[mid] > nums[end]) start = mid+1;
                else end = mid-1;
            }
            
            if (target < nums[left]) left = mid;
            else right = mid;
        }
        
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        
        return -1;
    }
};
