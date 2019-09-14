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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
    bool operator()(const ListNode *node1, const ListNode *node2) const {
        return node1->val < node2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        
        multiset<ListNode*, cmp> heapNodes;
        for (auto& headList : lists) {
            if(headList)
                heapNodes.insert(headList);
        }
        
        ListNode *result = new ListNode(0), *resultPtr = result;
        while (!heapNodes.empty()) {
            result->next = *heapNodes.begin();
            result = result->next;
            if ((*heapNodes.begin())->next)
                heapNodes.insert((*heapNodes.begin())->next);
            heapNodes.erase(heapNodes.begin());
        }
        
        return resultPtr->next;
    }
};
