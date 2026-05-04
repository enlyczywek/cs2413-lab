#include <stdbool.h>

/*
Question 1: Bubble Sort

Description:
Implement two versions of bubble sort for an integer array.

1. bubbleSort:
   Implement the basic bubble sort algorithm.
   Repeatedly compare adjacent elements and swap them if they are
   in the wrong order. After each pass, the largest unsorted element
   should move to its correct position.

2. bubbleSortOptimized:
   Implement an improved version of bubble sort.
   This version should stop early if a full pass completes without
   any swaps, which means the array is already sorted.

Both functions should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
*/

void bubbleSort(int arr[], int size) {
    // TODO: implement basic bubble sort
    int temp = 0;

    for(int h = 0; h < size; h++){
        for (int i = 0; i < size - 1; i++){
            if (arr[i] > arr[i + 1]){
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    (void)arr;
    (void)size;
}

void bubbleSortOptimized(int arr[], int size) {
    // TODO: implement optimized bubble sort with early stopping
    int temp = 0;
    int swap = 0;

    for(int h = 0; h < size; h++){
        swap = 0;
        for (int i = 0; i < size - 1; i++){
            if (arr[i] > arr[i + 1]){
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap++;                
            }
            
        }

        if (swap == 0) break;

    }
    (void)arr;
    (void)size;
}
