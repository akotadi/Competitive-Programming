/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        
        ListNode *root = new ListNode(0), *rootPtr = root;
        ListNode *current = head, *next = head->next;
        while(current && next){
            root->next = next;
            current->next = next->next;
            next->next = current;
            
            if(current->next) root = current, next = current->next->next, current = current->next;
            else current = nullptr, next = nullptr;
        }
        
        return rootPtr->next;
    }
};