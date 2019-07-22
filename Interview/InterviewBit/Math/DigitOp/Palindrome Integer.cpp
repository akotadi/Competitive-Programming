/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False
 */



int Solution::isPalindrome(int A) {
    if(A < 0) return 0;
    string s = to_string(A);
    uint32_t i = 0, j = s.size() - 1;
    while(i != j && j != i - 1){
        // cout << s[i] << " : " << s[j] << endl;
        if(s[i++] == s[j--]) continue;
        return 0;
    }
    return 1;
}
