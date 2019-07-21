/*
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

class Solution {
public:
    Solution(vector<int>& nums) {
        int n = nums.size();
        N = n;
        
        numbers.resize(n);
        for(int i = 0; i < n; i++) numbers[i] = {i, nums[i]};
        
        srand (time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        sort(numbers.begin(), numbers.end());
        
        vector<int> result;
        for(auto it : numbers) result.emplace_back(it.second);
        
        return result;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < N; i++) swap(numbers[i], numbers[rand() % N]);
        
        vector<int> result;
        for(auto it : numbers) result.emplace_back(it.second);
        
        return result;
    }
private:
    int N;
    vector< pair<int, int> > numbers;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */