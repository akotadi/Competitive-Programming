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