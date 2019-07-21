/*
Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

Return its preorder traversal as: [5,6,3,2,4,1].

 

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
    vector<int> postorder(Node* root) {
        vector<int> result;
        
        if(!root) return result;
        
        stack<Node*> traverse;
        traverse.push(root);
        while(!traverse.empty()){
            Node* current = traverse.top();
            traverse.pop();
            
            for(auto it = current->children.begin(); it != current->children.end(); it++)
                traverse.push(*it);
            
            result.emplace(result.begin(), current->val);
        }
        
        return result;
    }
};