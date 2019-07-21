/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prevTarget = head, *tail = prevTarget->next;
        while(tail && n--) tail = tail->next;
        if(n > 0) return head->next;
        while(tail){
            tail = tail->next;
            prevTarget = prevTarget->next;
        }
        prevTarget->next = prevTarget->next->next;
        
        return head;
    }
};