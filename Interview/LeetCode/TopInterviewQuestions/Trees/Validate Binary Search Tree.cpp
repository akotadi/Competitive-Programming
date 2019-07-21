/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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

#define INF (1 << 60)

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return isValidBSTUtil(root);
    }
private:
    TreeNode* check = NULL;
    
    bool isValidBSTUtil(TreeNode* root){
        if (!root) {
            return true;
        }

        // Judge the left tree.
        if (!isValidBSTUtil(root->left)) {
            return false;
        }

        // judge the sequence.
        if (check && root->val <= check->val) {
            return false;
        }
        check = root;

        // Judge the right tree.
        if (!isValidBSTUtil(root->right)) {
            return false;
        }

        return true;
    }
};