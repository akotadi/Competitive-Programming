/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

class Solution {
public:
    int romanToInt(string s) {
        string aux = "";
        int index = 0, result = 0;
        while(index < s.size()){
            if(s[index] == 'M'){
                while(index < s.size() && (s[index] == 'M')) aux += s[index++];
                result += parseThousands(aux);
                aux = "";
            }
            if(s[index] == 'C' || s[index] == 'D'){
                while(index < s.size() && (s[index] == 'C' || s[index] == 'D' || s[index] == 'M')) aux += s[index++];
                result += parseHundreds(aux);
                aux = "";
            }
            if(s[index] == 'X' || s[index] == 'L'){
                while(index < s.size() && (s[index] == 'X' || s[index] == 'L' || s[index] == 'C')) aux += s[index++];
                result += parseTens(aux);
                aux = "";
            }
            if(s[index] == 'I' || s[index] == 'V'){
                while(index < s.size() && (s[index] == 'I' || s[index] == 'V' || s[index] == 'X')) aux += s[index++];
                result += parseUnits(aux);
                aux = "";
            }
        }
        return result;
    }
private:
    int parseUnits(string s){
        if(s.size() == 0) return 0;
        if(s[0] == 'I'){
            if(s.size() == 1) return 1;
            if(s[1] == 'V') return 4;
            if(s[1] == 'X') return 9;
            return s.size();
        }else if(s[0] == 'V'){
            return (5 + (s.size() - 1));
        }
        return 0;
    }

    int parseTens(string s){
        if(s.size() == 0) return 0;
        if(s[0] == 'X'){
            if(s.size() == 1) return 10;
            if(s[1] == 'L') return 40;
            if(s[1] == 'C') return 90;
            return 10 * s.size();
        }else if(s[0] == 'L'){
            return 50 + (10 * (s.size() - 1));
        }
        return 0;
    }

    int parseHundreds(string s){
        if(s.size() == 0) return 0;
        if(s[0] == 'C'){
            if(s.size() == 1) return 100;
            if(s[1] == 'D') return 400;
            if(s[1] == 'M') return 900;
            return 100 * s.size();
        }else if(s[0] == 'D'){
            return 500 + (100 * (s.size() - 1));
        }
        return 0;
    }

    int parseThousands(string s){
        return s.size() * 1000;
    }
};