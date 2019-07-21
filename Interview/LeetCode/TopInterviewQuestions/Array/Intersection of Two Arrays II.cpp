/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

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