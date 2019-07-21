/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/

class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        
        if(n == 0) return 0;
        
        int i = 0;
        bool flag = false;
        while(i < n && str[i] == ' ') i++;
        // All the characters are whitespaces
        if(i == n) return 0;
        // The number is negative
        if(str[i] == '-'){
            flag = true;
            i++;
        }else if(str[i] == '+') i++;
        // If not number, the answer is not possible
        if(!isdigit(str[i])) return 0;
        while(i < n && isdigit(str[i])){
            if(str[i] == '0') i++;
            else break;
        }
        if(i == n) return 0;
        if(!isdigit(str[i])) return 0;
        // We check where is the end of the number
        int j = i+1;
        while(j < n){
            if(isdigit(str[j])) j++;
            else break;
        }
        
        // Overflow the integer by digits
        if(j - i >= 11) return ((flag)?(INT_MIN):(INT_MAX));
        
        int64_t aux = 0;
        while(i < j) aux = ((aux*10) + (str[i++] - '0'));
        
        if(flag){
            aux *= -1;
            if(aux < INT_MIN) return INT_MIN;
            else return aux;
        }else if(aux > INT_MAX) return INT_MAX;
        else return aux;
    }
};