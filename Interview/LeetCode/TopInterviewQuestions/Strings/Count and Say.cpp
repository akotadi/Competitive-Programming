/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n < 2) return "1";
        
        string last = "1";
        for(int i = 2; i <= n; i++){
            string aux = "";
            char check = 'a';
            int counter = 0;
            for(auto c : last){
                if(c != check){
                    if(counter != 0){
                        aux += (counter + '0');
                        aux += check;
                    }
                    counter = 0;
                    check = c;
                    counter++;
                }else counter++;
            }
            if(counter){
                aux += (counter + '0');
                aux += check;
            }
            
            last = aux;
        }
        
        return last;
    }
};