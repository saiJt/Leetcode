/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    struct ListNode* slow;
    struct ListNode* fast;
    
    dummy->next = head;
    slow = dummy;
    fast = head;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }    

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
   
    return dummy->next ;

}
