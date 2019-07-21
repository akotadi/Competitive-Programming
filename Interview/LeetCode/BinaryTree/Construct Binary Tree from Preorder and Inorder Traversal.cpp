/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        int n = inOrder.size();
    
        if(n == 0 || n != preOrder.size()) return NULL;
        
        return buildTreeUtil(inOrder, preOrder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* buildTreeUtil(vector<int>& inOrder, vector<int>& preOrder, int leftI, int rightI, int leftP, int rightP) {    
        if(rightI < leftI) return NULL;
        if(leftI == rightI) return new TreeNode(inOrder[leftI]);

        TreeNode* root = new TreeNode(preOrder[leftP]);

        int indexRoot = 0;
        while(inOrder[leftI + indexRoot] != root->val) indexRoot++;

        if(leftI + indexRoot != leftI){
            root->left = buildTreeUtil(inOrder, preOrder, leftI, leftI + indexRoot - 1, leftP + 1, leftP + indexRoot);
        }

        if(leftI + indexRoot != rightI){
            root->right = buildTreeUtil(inOrder, preOrder, leftI + indexRoot + 1, rightI, leftP + indexRoot + 1, rightP);
        } 

        return root;
    }
};