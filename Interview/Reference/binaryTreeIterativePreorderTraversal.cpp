/**
 * Binary Tree Iterative Preorder Traversal algorithm, uses an stack
 * to keep follow of the nodes to visit, visit the top of the stack
 * at each iteration and push his right and left child in that order.
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(n)
 *
 * @Identify:
 *
 * @Practice:
 *     - Binary Tree Preorder Traversal
 */
vector<int> preorderTraversal(TreeNode *root) {
    auto result = vector<int>();

    if (!root) return result;

    auto traverse = stack<TreeNode *>();
    traverse.push(root);

    while (!traverse.empty()) {
        auto current = traverse.top();
        traverse.pop();
        result.push_back(current->val);

        if (current->right) traverse.push(current->right);

        if (current->left) traverse.push(current->left);
    }

    return result;
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
