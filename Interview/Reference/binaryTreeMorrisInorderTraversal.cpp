/**
 * Binary Tree Morris Inorder Traversal algorithm, is based on
 * Threaded Binary Tree. In this traversal, we first create links
 * to Inorder successor and print the data using these links, and
 * finally revert the changes to restore original tree.
 *
 * Threaded Binary Tree: "A binary tree is threaded by making all
 * right child pointers that would normally be null point to the
 * in-order successor of the node (if it exists), and all left child
 * pointers that would normally be null point to the in-order
 * predecessor of the node."
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(1)
 *
 * @Identify:
 *
 * @Practice:
 *     - Binary Tree Inorder Traversal
 */
vector<int> inorderMorrisTraversal(TreeNode *root) {
    auto result = vector<int>();
    auto current = root;

    while (current) {
        if (current->left) {
            // Find the inorder predecessor of current
            auto prev = current->left;

            while (prev->right && prev->right != current)
                prev = prev->right;

            // Make current as the right child of its inorder
            // predecessor
            if (!prev->right) {
                prev->right = current;
                current = current->left;
            }
            // Revert the changes made in the 'if' part to restore
            // the original tree i.e., fix the right child of
            // predecessor
            else {
                prev->right = NULL;
                result.push_back(current->val);
                current = current->right;
            }
        } else {
            result.push_back(current->val);
            current = current->right;
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

