/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return NULL;
        if(n == 1) return new TreeNode(nums[0]);
        
        return sortedArrayToBSTUtil(nums, 0, n-1);
    }
private:
    TreeNode* sortedArrayToBSTUtil(vector<int> &nums, int left, int right){
        if(left > right) return NULL;
        
        int mid = (right + left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTUtil(nums, left, mid - 1);
        root->right = sortedArrayToBSTUtil(nums, mid + 1, right);
        
        return root;
    }
};