/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        queue<TreeNode*> left, right;
        left.push(root->left);
        right.push(root->right);
        
        while(!left.empty() && !right.empty()){
            TreeNode *leftNode = left.front(), *rightNode = right.front();
            left.pop();
            right.pop();
            
            // Two valid nodes
            if(leftNode && rightNode){
                // Compare its values
                if(leftNode->val != rightNode->val) return false;
                left.push(leftNode->left);
                left.push(leftNode->right);
                right.push(rightNode->right);
                right.push(rightNode->left);
            }else if(leftNode || rightNode) return false;
            
        }
        
        return true;
        
    }
};