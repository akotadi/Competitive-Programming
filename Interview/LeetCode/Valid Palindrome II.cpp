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
    bool validPalindrome(string s) {
        if (isPalindrome(s)) return true;
        else {
            int i = 0, j = s.size()-1;
            for (; i < j; i++, j--) {
                if (s[i] != s[j]) 
                    break;
            }
            if (i+1 == j) return true;
            else
                return isPalindrome(s.substr(i, j - i)) || isPalindrome(s.substr(i+1, j - i));
        }
    }
private:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size()-1; i < j; i++, j--) {
            if(s[i] != s[j]) 
                return false;
        }
        return true;
    }
};
