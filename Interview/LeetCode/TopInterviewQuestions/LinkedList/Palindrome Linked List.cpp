/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(!head || !(head->next)) return true;
        
        int n = 0;
        ListNode *traverse = head;
        while(traverse){
            n++;
            traverse = traverse->next;
        }
        if(n & 1) n++;
        n >>= 1;
        
        traverse = head;
        while(--n) traverse = traverse->next;
        ListNode *aux = traverse->next;
        traverse->next = NULL;
        traverse = reverseList(aux);
        while(head && traverse){
            if(head->val != traverse->val) return false;
            head = head->next;
            traverse = traverse->next;
        }
        
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)) return head;
        
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};