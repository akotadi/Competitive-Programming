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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n == 0) return {};
        
        int left = -1, right = n, mid;
        while(left+1 < right){
            mid = left + ((right - left) >> 1);
            if(arr[mid] < x) left = mid;
            else right = mid;
        }
        
        vector<int> result;
        while(k && right < n && arr[right] == x){
            result.emplace_back(arr[right++]);
            k--;
        }
        while(k--){
            if(left >= 0 && right < n){
                if((x - arr[left]) <= (arr[right] - x)) result.emplace(result.begin(), arr[left--]);
                else result.emplace_back(arr[right++]);
            }else if(left >= 0) result.emplace(result.begin(), arr[left--]);
            else result.emplace_back(arr[right++]);
        }
        
        return result;
    }
};
