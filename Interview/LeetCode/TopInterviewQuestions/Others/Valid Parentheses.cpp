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
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        if(s.size() < 2) return !(s.size());
        
        stack<char> check;
        for(auto c : s){
            switch(c){
                case '(':
                case '[':
                case '{':
                    check.push(c);
                    break;
                case ')':
                    if(check.empty() || check.top() != '(') return false;
                    else check.pop();
                    break;
                case ']':
                    if(check.empty() || check.top() != '[') return false;
                    else check.pop();
                    break;
                case '}':
                    if(check.empty() || check.top() != '{') return false;
                    else check.pop();
                    break;
                default:
                    continue;
            }
        }
        
        return check.empty();
    }
};