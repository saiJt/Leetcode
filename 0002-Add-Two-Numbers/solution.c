/**
 * Definition for singly-linked list.
 * Each node stores a single digit and
 * a pointer to the next node.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Dummy node used as a placeholder for the head of the result list.
    // The actual head of the list will be dummy->next.
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;

    // Tail pointer always points to the last node in the result list.
    struct ListNode* tail = dummy;

    // Carry value for digit overflow.
    int carry = 0;

    // Continue while at least one list still has nodes.
    while (l1 != NULL || l2 != NULL) {
        // Create a new node for the current digit.
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->next = NULL;

        // Safely extract values from l1 and l2.
        // If a list is NULL, its value is treated as 0.
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        // Compute the sum for the current digit.
        int sum = 0;

        // Apply carry from the previous digit if it exists.
        if (carry == 1) {
            sum += 1;
            carry = 0;
        }

        // Add current digit values.
        sum += val1 + val2;

        // Handle digit overflow and update carry.
        if (sum > 9) {
            newNode->val = sum % 10;
            carry = 1;
        } else {
            newNode->val = sum;
        }

        // Append the new node to the result list.
        tail->next = newNode;
        tail = newNode;

        // Advance input list pointers if possible.
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    // If a carry remains after processing all digits,
    // append one final node.
    if (carry == 1) {
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = 1;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    // Return the head of the resulting linked list.
    return dummy->next;
}
