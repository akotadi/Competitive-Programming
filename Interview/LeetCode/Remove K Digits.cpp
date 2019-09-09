class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == 0 || k >= n) return "0";
        
        stack<char> check;
        
        // Iterate over and make a crecient sequence
        for (const char& digit : num) {
            // If the stack has element and we can take over yet
            while (!check.empty() && k) {
                // If not ascendent, pop
                if (check.top() > digit) {
                    check.pop();
                    k--;
                }
                else
                    break;
            }
            check.push(digit);
        }
        
        // If we need to take elements, pop
        while(!check.empty() && k--) {
            check.pop();
        }
        
        // Append the elements to the final result
        string result = "";
        while(!check.empty()) {
            result += check.top();
            check.pop();
        }
        
        // Reverse the result
        reverse(result.begin(), result.end());
        
        auto it = result.find_first_of("123456789");
        if (it == string::npos)
            return "0";
        
        return result.substr(it, n - it);
    }
};
