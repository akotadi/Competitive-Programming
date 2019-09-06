class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        
        int left = 0, right = n-1;
        if (nums[left] > nums[right]) {
            int start = left, end = right, mid;
            while(start <= end) {
                mid = start + ((end - start) >> 1);
                if (nums[mid] < nums[(mid+1)%n] && nums[mid] < nums[((mid-1)+n)%n]) break;
                else if (nums[mid] > nums[end]) start = mid+1;
                else end = mid-1;
            }
            
            if (target < nums[left]) left = mid;
            else right = mid;
        }
        
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        
        return -1;
    }
};
