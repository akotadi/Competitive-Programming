class Solution {
public:
    Solution(vector<int>& w) {
        values.resize(w.size(), 0);
        totalSum = 0;
        for (const int& num : w) 
            totalSum += num;
        for (int i = 1; i < w.size(); i++) 
            values[i] = values[i-1] + w[i-1];
        mt_rand.seed(chrono::high_resolution_clock::now().time_since_epoch().count());
    }
    
    int pickIndex() {
        int location = mt_rand() % totalSum;
        auto it = lower_bound (values.begin(), values.end(), location);
        if (it == values.end() || (*it != location && it != values.begin()))
            it--;
        return it - values.begin();
    }
private:
    vector<int> values;
    mt19937 mt_rand;
    int totalSum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
