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