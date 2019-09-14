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
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = -1, right = letters.size();
        while(left+1 < right){
            int mid = left + ((right - left) >> 1);
            if(letters[mid] > target) right = mid;
            else left = mid;
        }
        
        return letters[right%letters.size()];
    }
};
