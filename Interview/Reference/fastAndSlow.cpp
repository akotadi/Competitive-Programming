/**
 * Fast and Slow pointer algorithm, uses two pointers which move
 * through the array (or sequence/linked list) at different speeds.
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(1)
 *
 * @Identify:
 *     - The problem will deal with a loop in a linked list or array
 *     - When you need to know the position of a certain element or
 *     the overall length of the linked list.
 *
 * @Practice:
 *     - Linked List Cycle (easy)
 *     - Palindrome Linked List (medium)
 *     - Cycle in a Circular Array (hard)
 */
ListNode *fastAndSlowCycle(ListNode *head) {
    if (!head) return nullptr;

    auto slow = head, fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return fastAndSlowStartCycle(slow, head);
    }

    return nullptr;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *fastAndSlowStartCycle(ListNode *loopNode, ListNode *head) {
    auto headNode = head;

    while (loopNode != headNode) {
        loopNode = loopNode->next;
        headNode = headNode->next;
    }

    return loopNode;
}
