/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next= head;
    struct ListNode* prev = dummy;


    while (prev->next != NULL && prev->next->next != NULL) {
        struct ListNode* a = prev->next;
        struct ListNode* b = a->next;
        struct ListNode* next = b->next;

        prev->next = b;
        b->next = a;
        a->next = next;
        prev = a;
    }

    return dummy->next;

}
