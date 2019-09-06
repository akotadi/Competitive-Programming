class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n == 0) return {};
        
        int left = -1, right = n, mid;
        while(left+1 < right){
            mid = left + ((right - left) >> 1);
            if(arr[mid] < x) left = mid;
            else right = mid;
        }
        
        vector<int> result;
        while(k && right < n && arr[right] == x){
            result.emplace_back(arr[right++]);
            k--;
        }
        while(k--){
            if(left >= 0 && right < n){
                if((x - arr[left]) <= (arr[right] - x)) result.emplace(result.begin(), arr[left--]);
                else result.emplace_back(arr[right++]);
            }else if(left >= 0) result.emplace(result.begin(), arr[left--]);
            else result.emplace_back(arr[right++]);
        }
        
        return result;
    }
};
