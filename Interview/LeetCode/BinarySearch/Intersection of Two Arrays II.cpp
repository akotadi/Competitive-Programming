class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        vector<int> result;
        if(n == 0 || m == 0) return result;
        
        unordered_map<int, int> check;
        for(auto number : nums1) check[number]++;
        for(auto number : nums2){
            if(check.find(number) != check.end()){
                result.emplace_back(number);
                if(check[number] - 1 == 0) check.erase(number);
                else check[number]--;
            }
        }
        
        return result;
    }
};
