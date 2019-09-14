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
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
 */



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        
        vector<int> row;
        int counter = 0;
        while(rowIndex-- >= 0){
            prev = row;
            row.clear();
            row.emplace_back(1);
            for(int i = 0; i < counter; ++i){
                if(i == counter - 1) row.emplace_back(1);
                else row.emplace_back(prev[i] + prev[i + 1]);
            }
            counter++;
        }
        return row;
    }
};