class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        vector<int> leftProduct(n, 1), rightProduct(n, 1);
        for (int i = 1; i < n; i++)
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
        for (int i = n-2; i >= 0; i--)
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        
        vector<int> result;
        for (int i = 0; i < n; i++)
            result.emplace_back(leftProduct[i] * rightProduct[i]);
        
        return result;
    }
};
