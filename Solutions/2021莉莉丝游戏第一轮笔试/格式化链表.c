struct ListNode* formatList(struct ListNode* head) {
    if (!head) return NULL;

    // split odd / even
    int odd = 1;
    struct ListNode *oddList = NULL, *evenList = NULL, *p = head;
    while (p) {
        struct ListNode *r = p; p = p->next;
        if (odd) {
            r->next = oddList;
            oddList = r;
        } else {
            r->next = evenList;
            evenList = r;
        }
        odd = !odd;
    }


    // reverse even
    struct ListNode *even_rev = NULL;
    p = evenList;
    while (p) {
        struct ListNode *r = p; p = p->next;
        r->next = even_rev;
        even_rev = r;
    }
    
    // concat
    p = oddList;
    while (p->next) p = p->next;
    p->next = even_rev;

    return oddList;
}