/**
 * Binary Tree Iterative Postorder Traversal algorithm, visit the nodes
 * according to the requirement, recursively uses the memory stack to
 * visit all the nodes
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(n)
 *
 * @Identify:
 *
 * @Practice:
 *     - Binary Tree Postorder Traversal
 */
vector<int> postorderTraversal(TreeNode *root) {
    auto result = vector<int>();

    if (!root) return result;

    auto traverse = stack<TreeNode *>();
    TreeNode *current = root, * last = nullptr;

    while (current || !traverse.empty()) {
        if (current) {
            traverse.push(current);
            current = current -> left;
        } else {
            auto check = traverse.top();

            if (check->right && last != check->right)
                current = check -> right;
            else {
                result.push_back(check->val);
                last = check;
                traverse.pop();
            }
        }
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
