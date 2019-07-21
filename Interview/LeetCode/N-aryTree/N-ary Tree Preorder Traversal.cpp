/*
Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

Return its preorder traversal as: [1,3,5,6,2,4].

 

Note:

Recursive solution is trivial, could you do it iteratively?
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        
        if(!root) return result;
        
        stack<Node*> traverse;
        traverse.push(root);
        while(!traverse.empty()){
            Node* current = traverse.top();
            traverse.pop();
            
            result.emplace_back(current->val);
            
            for(auto it = current->children.rbegin(); it != current->children.rend(); it++)
                traverse.push(*it);
        }
        
        return result;
    }
};