/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

#define GMOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        
        if(n < m) return -1;
        if(m == 0 || n == 0) return 0;
        
        
        int patternHash = hashFunction(haystack.substr(0, m));
        int keyHash = hashFunction(needle);
        
        if(patternHash == keyHash) return 0;
        
        for(int i = 0; i < n - m; i++){
            patternHash = newHashNumber(patternHash, haystack[i], haystack[m + i], m);
            if(patternHash == keyHash) return i + 1;
        }
        
        return -1;
    }
private:
    const int base = 29;
    const int mod = 1e9 + 9;
    vector<int64_t> a_pow;
    
    // hash function: (a_1)x^(n-1) + (a_2)x^(n-2) + ... + a_n
    int hashFunction(string const& s){
        int64_t hashNumber = 0;
        int64_t p_pow = 1;
        a_pow.push_back(p_pow);
        for (auto c = s.rbegin(); c != s.rend(); ++c) {
            hashNumber = (hashNumber + ((*c) - 'a' + 1) * p_pow) % mod;
            p_pow = (p_pow * base) % mod;
            a_pow.push_back(p_pow);
        }
        
        return hashNumber % mod;
    }
    
    // calculate new hash value by previous hash value
    // new_value = (H - (a_1)x^(n-1)) * x + a_(n+1)
    int newHashNumber(int oldHashNumber, char oldCharacter, char newCharacter, int size){
        int64_t newHashNumber = oldHashNumber;
        newHashNumber -= ((oldCharacter - 'a' + 1) * a_pow[size-1]);
        newHashNumber = GMOD(newHashNumber, mod);
        //newHashNumber %= mod;
        newHashNumber *= base;
        newHashNumber = GMOD(newHashNumber, mod);
        //newHashNumber %= mod;
        newHashNumber += (newCharacter - 'a' + 1);
        
        return newHashNumber % mod;
    }
};