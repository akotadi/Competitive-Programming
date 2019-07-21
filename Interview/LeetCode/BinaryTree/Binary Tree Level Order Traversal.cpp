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