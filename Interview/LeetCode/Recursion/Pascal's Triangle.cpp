/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > result;
        if(numRows == 0) return result;
        
        vector<int> row;
        int counter = 0;
        while(numRows --> 0){
            row.clear();
            row.emplace_back(1);
            for(int i = 0; i < counter; ++i){
                if(i == counter - 1) row.emplace_back(1);
                else row.emplace_back(result[counter - 1][i] + result[counter - 1][i + 1]);
            }
            result.emplace_back(row);
            counter++;
        }
        return result;
    }
};