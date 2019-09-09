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
