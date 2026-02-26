// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement

    if (head == NULL || head->next == NULL) return false;

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (slow->next != NULL && fast->next != NULL && fast != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow){
            return true;
        }
    }

    return false;
}