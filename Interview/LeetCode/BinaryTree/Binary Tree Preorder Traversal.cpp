/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(!root) return result;
        
        stack<TreeNode*> traverse;
        traverse.push(root);
        while(!traverse.empty()){
            TreeNode *current = traverse.top();
            traverse.pop();
            
            result.emplace_back(current->val);
            if(current->right) traverse.push(current->right);
            if(current->left) traverse.push(current->left);
        }
        
        return result;
    }
};