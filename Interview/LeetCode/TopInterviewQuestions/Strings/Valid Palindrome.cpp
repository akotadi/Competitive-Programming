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
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        
        if(n < 2) return true;
        
        transform(s.begin(), s.end(), s.begin(), ::toupper); 
        
        int i = 0, j = n-1;
        while(i < j){
            if(!validChar(s[i])) i++;
            else if(!validChar(s[j])) j--;
            else if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
private:
    bool validChar(char &a){
        if(a < '0') return false;
        else if(a > '9' && a < 'A') return false;
        else if(a > 'Z') return false;
        else return true;
    }
};