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
class Solution {class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        map<int, int> storeGreaters;
        int i = 0;
        // Store the first k elements in our map
        while (k --> 0) {
            storeGreaters[nums[i++]]++;
        }
        
        // Continue adding the numbers into the map and deleting one from the front
        while (i < n) {
            storeGreaters[nums[i++]]++;
            int firstNumber = (*(storeGreaters.begin())).first;
            if(storeGreaters[firstNumber] == 1) storeGreaters.erase(firstNumber);
            else storeGreaters[firstNumber]--;
        }
        
        // The kth largest element is at front
        int kthLargestElement = (*(storeGreaters.begin())).first;
        return kthLargestElement;
    }
};
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        map<int, int> storeGreaters;
        int i = 0;
        // Store the first k elements in our map
        while (k --> 0) {
            storeGreaters[nums[i++]]++;
        }
        
        // Continue adding the numbers into the map and deleting one from the front
        while (i < n) {
            storeGreaters[nums[i++]]++;
            int firstNumber = (*(storeGreaters.begin())).first;
            if(storeGreaters[firstNumber] == 1) storeGreaters.erase(firstNumber);
            else storeGreaters[firstNumber]--;
        }
        
        // The kth largest element is at front
        int kthLargestElement = (*(storeGreaters.begin())).first;
        return kthLargestElement;
    }
};
