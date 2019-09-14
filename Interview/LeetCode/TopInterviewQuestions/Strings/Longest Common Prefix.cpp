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
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        if(n == 0) return "";
        if(n == 1) return strs[0];
        
        Trie check;
        for(auto word : strs){
            if(word.empty()) return "";
            else check.insert(word);
        }
        
        return check.longestCommonPrefix(strs.size());
        
    }
private:
    struct Trie {

        struct Node {
            unordered_map<char, Node *> ch;
            int w = 0, wpt = 0;
        };

        Node *root = new Node();

        // O(STR.SIZE)
        void insert(string str) {
            Node *curr = root;
            for (auto &c : str) {
                if (!curr->ch.count(c))
                    curr->ch[c] = new Node();
                curr->wpt++, curr = curr->ch[c];
            }
            curr->wpt++, curr->w++;
        }
        
        string longestCommonPrefix(int numberWords){
            Node *curr = root;
            string result = "";
            while(curr){
                if((curr->ch.empty())) return result;
                if((curr->ch.size()) > 1) return result;
                else{
                    if(curr->ch.begin()->second->wpt == numberWords){
                        result += curr->ch.begin()->first;
                        curr = curr->ch.begin()->second;
                    }else{
                        return result;
                    }
                }
            }
            return result;
        }
        
    };
};