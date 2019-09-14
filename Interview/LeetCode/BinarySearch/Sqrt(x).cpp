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
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        
        int left = 0, right = x;
        while(left < right) {
            int64_t mid = left + ((right - left) >> 1);
            if (mid * mid == x) return mid;
            else if (mid * mid < x) left = mid+1;
            else right = mid-1;
        }
        int64_t check = left*left;
        return (check <= x)?(left):(left-1);
    }
};
