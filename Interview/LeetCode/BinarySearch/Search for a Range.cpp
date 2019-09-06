class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) right = mid;
            else if(nums[mid] < target) left = mid;
            else right = mid;
        }
        
        if(nums[right] != target && nums[left] != target) return {-1, -1};
        vector<int> result;
        result.emplace_back((nums[left] == target)?(left):(right));
        left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) left = mid;
            else if(nums[mid] < target) left = mid;
            else right = mid;
        }
        result.emplace_back((nums[right] == target)?(right):(left));
        
        return result;
    }
};
