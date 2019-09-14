/*
 * Copyright (c) 2019 ManuelCH.
 *
 * This file is part of Interview-solutions 
 * (see https://github.com/akotadi).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n == 0) return {};
        set< vector<int> > result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        combinationSumUtil(candidates, target, result, current, 0, 0);
        
        vector< vector<int> > a;
        for(auto& v : result) 
            a.emplace_back(v);
        
        return a;
    }
private:
    bool combinationSumUtil(vector<int>& candidates, int target, set< vector<int> > &result, vector<int> current, int index, int currSum) {
        if(currSum == target){
            result.insert(current);
            return true;
        } else if(index == candidates.size()){
            return currSum < target;
        } else if(currSum > target) {
            return false;
        }
        
        for(int i = index; i < candidates.size(); i++) {
            current.emplace_back(candidates[i]);
            if(!combinationSumUtil(candidates, target, result, current, i, currSum + candidates[i])){
                current.pop_back();
                break;
            }
            current.pop_back();
        }
        
        return true;
    }
};
