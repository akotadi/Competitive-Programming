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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        int result = 1;
        while (!bfs.empty()) {
            TreeNode *current = bfs.front();
            bfs.pop();
            if (current->left) {
                result++;
                bfs.push(current->left);
                if (current->right) {
                    result++;
                    bfs.push(current->right);
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        
        return result;
    }
};
