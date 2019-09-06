class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        if(n < 2) return {};
        
        int left = 0, right = n-1;
        while(left+1 < right){
            int current = numbers[left] + numbers[right];
            if(current == target) break;
            else if(current < target) left++;
            else right--;
        }
        
        return {++left, ++right};
    }
};
