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