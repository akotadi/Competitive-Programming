/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(!root) return result;
        
        stack<TreeNode*> traverse;
        TreeNode *current = root;
        while(current || !traverse.empty()){
            while(current){
                traverse.push(current);
                current = current->left;
            }
            
            current = traverse.top();
            traverse.pop();
            
            result.emplace_back(current->val);
            
            current = current->right;
        }
        
        return result;
    }
};