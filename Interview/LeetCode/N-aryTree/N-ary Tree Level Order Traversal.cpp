/*
Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

We should return its level order traversal:

[
     [1],
     [3,2,4],
     [5,6]
]
 

Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.
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
    vector<vector<int>> levelOrder(Node* root) {
        vector< vector<int> > result;
        
        if(!root) return result;
        
        queue< pair<Node*, int> > bfs;
        bfs.push({root, 0});
        
        while(!bfs.empty()){
            pair<Node*, int> current = bfs.front();
            bfs.pop();
            if(current.second == result.size()) result.emplace_back(vector<int>());
            result[current.second].emplace_back((current.first)->val);
            for(auto node : (current.first)->children)
                bfs.push({node, current.second + 1});
        }
        
        return result;
    }
};