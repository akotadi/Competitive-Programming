/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        int64_t aux = x;
        if(aux < 0){
            flag = true;
            aux *= -1;
        }
        string s = to_string(aux);
        reverseString(s);
        char * pEnd;
        aux = strtol(s.c_str(), &pEnd, 10);
        if(aux > INT_MAX || aux < INT_MIN) return 0;
        else return (int)aux * ((flag)?-1:1);
    }
    
private:
    void reverseString(string& s) {
        int n = s.size();
        
        if(n < 2) return;
        
        for(int i = 0, j = n-1; i < j; i++, j--) swapi(s[i], s[j]);
    }
    
    void swapi(char &a, char &b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
};