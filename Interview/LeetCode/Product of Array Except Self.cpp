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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        vector<int> leftProduct(n, 1), rightProduct(n, 1);
        for (int i = 1; i < n; i++)
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
        for (int i = n-2; i >= 0; i--)
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        
        vector<int> result;
        for (int i = 0; i < n; i++)
            result.emplace_back(leftProduct[i] * rightProduct[i]);
        
        return result;
    }
};
