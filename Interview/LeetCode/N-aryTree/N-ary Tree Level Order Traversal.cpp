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