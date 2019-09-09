class Solution {
public:
    bool validPalindrome(string s) {
        if (isPalindrome(s)) return true;
        else {
            int i = 0, j = s.size()-1;
            for (; i < j; i++, j--) {
                if (s[i] != s[j]) 
                    break;
            }
            if (i+1 == j) return true;
            else
                return isPalindrome(s.substr(i, j - i)) || isPalindrome(s.substr(i+1, j - i));
        }
    }
private:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size()-1; i < j; i++, j--) {
            if(s[i] != s[j]) 
                return false;
        }
        return true;
    }
};
