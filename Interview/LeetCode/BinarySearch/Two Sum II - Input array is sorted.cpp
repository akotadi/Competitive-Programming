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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        if(n < 2) return {};
        
        int left = 0, right = n-1;
        while(left+1 < right){
            int current = numbers[left] + numbers[right];
            if(current == target) break;
            else if(current < target) left++;
            else right--;
        }
        
        return {++left, ++right};
    }
};
