class Solution {class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        map<int, int> storeGreaters;
        int i = 0;
        // Store the first k elements in our map
        while (k --> 0) {
            storeGreaters[nums[i++]]++;
        }
        
        // Continue adding the numbers into the map and deleting one from the front
        while (i < n) {
            storeGreaters[nums[i++]]++;
            int firstNumber = (*(storeGreaters.begin())).first;
            if(storeGreaters[firstNumber] == 1) storeGreaters.erase(firstNumber);
            else storeGreaters[firstNumber]--;
        }
        
        // The kth largest element is at front
        int kthLargestElement = (*(storeGreaters.begin())).first;
        return kthLargestElement;
    }
};
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        map<int, int> storeGreaters;
        int i = 0;
        // Store the first k elements in our map
        while (k --> 0) {
            storeGreaters[nums[i++]]++;
        }
        
        // Continue adding the numbers into the map and deleting one from the front
        while (i < n) {
            storeGreaters[nums[i++]]++;
            int firstNumber = (*(storeGreaters.begin())).first;
            if(storeGreaters[firstNumber] == 1) storeGreaters.erase(firstNumber);
            else storeGreaters[firstNumber]--;
        }
        
        // The kth largest element is at front
        int kthLargestElement = (*(storeGreaters.begin())).first;
        return kthLargestElement;
    }
};
