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
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (n == 0) return true;
        
        // isAscendent: 0 - false, 1 - true, 2 - undefined;
        int8_t isAscendent = 2;
        for (int i = 1; i < n; i++) {
            // If equals, doesn't matter
            if (A[i] == A[i-1]) 
                continue;
            // If flag undefined, define it
            else if (isAscendent == 2) {
                if(A[i] < A[i-1]) 
                    isAscendent = 0;
                else 
                    isAscendent = 1;
            }
            else {
                if (isAscendent) {
                    if(A[i] > A[i-1]) 
                        continue;
                    else 
                        return false;
                } else {
                    if(A[i] < A[i-1]) 
                        continue;
                    else
                        return false;
                }
            }
            
        }
        
        return true;
    }
};
