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
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        
        if(!root) return "null";
        
        stack<TreeNode*> traverse;
        traverse.push(root);
        vector<int64_t> numbers;
        while(!traverse.empty()){
            TreeNode *current = traverse.top();
            traverse.pop();
            
            if(current){
                numbers.emplace_back(current->val);
                traverse.push(current->right);
                traverse.push(current->left);
            }else{
                numbers.emplace_back(INT_MIN - 1LL);
            }
        }
        
        for(int i = numbers.size() - 1; i > 0; i--){
            if(numbers[i] < INT_MIN) result += "null";
            else result += to_string(numbers[i]);
            result += ",";
        }
        result += to_string(numbers[0]);
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream tokenStream(data);
        string token;
        stack<TreeNode*> nodeStack;
        while (getline(tokenStream, token, ','))
        {
            TreeNode *current = nullptr;
            if(token != "null"){
                current = new TreeNode(stoi(token));
            }
            
            if(current){
                TreeNode *aux = nodeStack.top();
                nodeStack.pop();
                current->left = aux;
                aux = nodeStack.top();
                nodeStack.pop();
                current->right = aux;
            }
            
            nodeStack.push(current);
        }
        
        return nodeStack.top();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));