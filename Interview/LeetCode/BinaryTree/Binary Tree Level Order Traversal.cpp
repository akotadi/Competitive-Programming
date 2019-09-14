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
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > result;
        
        if(!root) return result;
        
        vector<int> values;
        queue<TreeNode*> currentLevel, nextLevel;
        nextLevel.push(root);
        while(!nextLevel.empty()){
            values.clear();
            copyQueue(currentLevel, nextLevel);
            while(!currentLevel.empty()){
                TreeNode *aux = currentLevel.front();
                currentLevel.pop();
                values.emplace_back(aux->val);
                if(aux->left) nextLevel.push(aux->left);
                if(aux->right) nextLevel.push(aux->right);
            }
            result.emplace_back(values);
        }
        
        return result;
    }
private:
    void copyQueue(queue<TreeNode*> &target, queue<TreeNode*> &objective){
        while(!objective.empty()){
            target.push(objective.front());
            objective.pop();
        }
    }
};