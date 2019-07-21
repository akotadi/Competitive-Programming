/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        
        if(n == 0) return -1;
        if(n == 1) return 0;
        
        unordered_map<char, int> check;
        for(auto c : s) check[c]++;
        for(int i = 0; i < n; i++){
            if(check[s[i]] == 1) return i;
        }
        
        return -1;
    }
};