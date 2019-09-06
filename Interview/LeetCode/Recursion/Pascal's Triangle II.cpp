/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
 */



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        
        vector<int> row;
        int counter = 0;
        while(rowIndex-- >= 0){
            prev = row;
            row.clear();
            row.emplace_back(1);
            for(int i = 0; i < counter; ++i){
                if(i == counter - 1) row.emplace_back(1);
                else row.emplace_back(prev[i] + prev[i + 1]);
            }
            counter++;
        }
        return row;
    }
};