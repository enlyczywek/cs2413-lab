/*
Question 1: Two Sum

Description:
Given an array of integers nums and an integer target, return the indices
of the two numbers such that they add up to target.

You may assume that each input has exactly one solution, and you may not
use the same element twice.

For this lab, you should solve the problem using a hash-based idea.

Function:
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

Notes:
- Return a dynamically allocated array of size 2.
- Set *returnSize = 2 before returning.
- The returned array will be freed by the caller.

Example:
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]

Hint:
As you scan the array, for each nums[i], think about whether the value
(target - nums[i]) has already appeared before.
*/

#include <stdlib.h>

/*
Optional helper structure for a hash table entry.

You may use this structure if you want to build your own hash table.
key   -> the number from the array
value -> the index of that number
*/
typedef struct Node {
    int value;
    int index;
    struct Node* next;
} Node;

/*
Optional table size for a simple hash table implementation.
You may change this index if needed.
*/
#define TABLE_SIZE 1009

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static int hash(int value);
static void insert(Node* table[], int value, int index);
static int find(Node* table[], int value, int* index);
static void freeTable(Node* table[]);

/*
Return an array of size 2 containing the indices of the two numbers
whose sum equals target.
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    /* Write your code here */

    Node* table[TABLE_SIZE] = {0};
    
    
    for (int i = 0; i < numsSize; i++){
        
        int complement = target - nums[i];
        int location;

        if (find(table, complement, &location)){
            int* result = (int*)malloc(2 * sizeof(int));

            result[0] = location;
            result[1] = i;

            *returnSize = 2;
            freeTable(table);
            return result;
        }
        insert(table, nums[i], i);
    }

    *returnSize = 0;
    freeTable(table);
    return NULL;
}

/*
Optional helper: compute a hash index for a key.
*/
static int hash(int value) {
    /* Write your code here if you use this helper */
    if (value < 0) value = -value;
    return value % TABLE_SIZE;
    return 0;
}

/*
Optional helper: insert (key, index) into the hash table.
*/
static void insert(Node* table[], int value, int index) {
    /* Write your code here if you use this helper */
    int ind = hash(value);
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = value;
    new->index = index;
    new->next = table[ind];
    table[ind] = new;
}

/*
Optional helper: search for key in the hash table.
If found, store the associated index in *index and return 1.
Otherwise return 0.
*/
static int find(Node* table[], int value, int* index) {
    /* Write your code here if you use this helper */
    int ind = hash(value);
    Node* current = table[ind];
    while(current != NULL) {
        if (current->value == value){
            *index = current->index;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

/*
Optional helper: free all memory used by the hash table.
*/
static void freeTable(Node* table[]) {
    /* Write your code here if you use this helper */
    for (int i = 0; i < TABLE_SIZE; i++){
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}