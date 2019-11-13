/**
 * Binary Tree Iterative Inorder Traversal algorithm, uses an stack
 * to keep follow of the nodes at the branch, when the left most
 * child is reached, visit the top of the stack and visit his
 * right child.
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(n)
 *
 * @Identify:
 *
 * @Practice:
 *     - Binary Tree Inorder Traversal
 */
vector<int> inorderTraversal(TreeNode *root) {
    auto result = vector<int>();

    if (!root) return result;

    auto traverse = stack<TreeNode *>();
    auto current = root;

    while (current || !traverse.empty()) {
        while (current) {
            traverse.push(current);
            current = current->left;
        }

        current = traverse.top();
        traverse.pop();
        result.push_back(current->val);
        current = current->right;
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
