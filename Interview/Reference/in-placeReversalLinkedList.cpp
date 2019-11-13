/**
 * In-place Reversal of Linked List algorithm, reverses one node at
 * a time starting with one variable (current) pointing to the head
 * of the linked list, and one variable (previous) will point to the
 * previous node that you have processed.
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(1)
 *
 * @Identify:
 *     - If you’re asked to reverse a linked list without using
 *     extra memory
 *
 * @Practice:
 *     - Reverse a Sub-list (medium)
 *     - Reverse every K-element Sub-list (medium)
 */
ListNode *reverse_N_Nodes(ListNode *head, int size) {
    auto newHead = head;

    while (size--) {
        auto prev = head->next;
        head->next = prev->next;
        auto curr = newHead;
        newHead = prev;
        prev->next = curr;
    }

    return newHead;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
