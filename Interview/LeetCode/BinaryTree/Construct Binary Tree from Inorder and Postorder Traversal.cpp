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
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
        int n = inOrder.size();
    
        if(n == 0 || n != postOrder.size()) return NULL;
        
        return buildTreeUtil(inOrder, postOrder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* buildTreeUtil(vector<int>& inOrder, vector<int>& postOrder, int leftI, int rightI, int leftP, int rightP) {    
        if(rightI < leftI) return NULL;
        if(leftI == rightI) return new TreeNode(inOrder[leftI]);

        TreeNode* root = new TreeNode(postOrder[rightP]);

        int indexRoot = 0;
        while(inOrder[leftI + indexRoot] != root->val) indexRoot++;

        if(leftI + indexRoot != leftI){
            root->left = buildTreeUtil(inOrder, postOrder, leftI, leftI + indexRoot - 1, leftP, leftP + indexRoot - 1);
        }

        if(leftI + indexRoot != rightI){
            root->right = buildTreeUtil(inOrder, postOrder, leftI + indexRoot + 1, rightI, leftP + indexRoot, rightP - 1);
        } 

        return root;
    }
};