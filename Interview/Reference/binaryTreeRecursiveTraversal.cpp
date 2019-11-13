/**
 * Binary Tree Recursive Traversal algorithm, visit the nodes according to the
 * requirement, recursively uses the memory stack to visit all the nodes
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(n) - Because memory stack
 *
 * @Identify:
 *
 * @Practice:
 *     - Binary Tree Preorder Traversal
 *     - Binary Tree Inorder Traversal
 *     - Binary Tree Postorder Traversal
 */
vector<int> treeTraversal(TreeNode *root) {
    auto result = vector<int>();
    treeTraversalUtil(root, result);
    return result;
}

void treeTraversalUtil(TreeNode *root, vector<int> &result) {
    if (!root) return;

    // Preorder Traversal
    // result.push_back(root->val);
    if (root->right) treeTraversalUtil(root->right);

    // Inorder Traversal
    // result.push_back(root->val);
    if (root->left) treeTraversalUtil(root->left);

    // Postorder Traversal
    // result.push_back(root->val);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
