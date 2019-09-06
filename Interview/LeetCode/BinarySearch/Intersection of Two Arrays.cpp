class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n == 0 || m == 0) return {};
        
        unordered_set<int> check;
        for(const int& num : nums1) check.insert(num);
        
        vector<int> result;
        for(const int& num : nums2){
            if(check.find(num) != check.end()){
                result.emplace_back(num);
                check.erase(num);
            }
        }
        
        return result;
    }
};
