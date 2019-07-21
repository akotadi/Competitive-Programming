ListNode* revert(ListNode* start) {
    if (!start) return NULL;

    ListNode *n1 = start;
    ListNode *n2 = n1->next;
    ListNode *n3;

    while (n2) {
        n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    start->next = NULL;

    return n1;
}