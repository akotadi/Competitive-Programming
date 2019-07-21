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