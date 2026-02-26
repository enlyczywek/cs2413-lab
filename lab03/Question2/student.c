// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement

      struct ListNode test;
      test.val = 0;
      test.next = head;
      struct ListNode* test_ptr = &test;      

      while ((test_ptr->next != NULL) && (test_ptr->next->next != NULL)){
            struct ListNode* first = test_ptr->next;
            struct ListNode* second = first->next;
                        
            first->next = second->next;
            second->next = first;

            test_ptr->next = second;
            test_ptr = first;
      }
    
       return test.next;
       
       
       
       
}