#include <stdio.h>
#include <stdlib.h>

/*
Hybrid Merge Sort Lab

Objective:
Implement a hybrid sorting algorithm that combines merge sort and insertion sort.

Idea:
- Merge sort has worst-case time complexity O(n log n).
- Insertion sort has worst-case time complexity O(n^2), but it is fast for small subarrays.
- Therefore, when the current subarray size is less than or equal to k,
  use insertion sort instead of continuing recursive merge sort.

Input array:
[39, 9, 81, 45, 90, 27, 72, 18]

Expected sorted output:
[9, 18, 27, 39, 45, 72, 81, 90]

Students need to complete:

1. insertionSort
2. merge
3. hybridMergeSort
*/

/*
Print the array.
Do not modify this function.
*/
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);

        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

/*
Check whether the array is sorted.
Do not modify this function.
*/
int isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}

/*
Sort arr[left...right] using insertion sort.
*/
void insertionSort(int arr[], int left, int right) {
    // TODO: implement insertion sort for arr[left...right]

    int temp = 0;
    int j = 0;

    for (int i = left + 1; i < right + 1; i++){
        temp = arr[i];
        j = i - 1;

        while (j >= left && temp <= arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

/*
Merge two sorted subarrays into one sorted subarray.
*/
void merge(int arr[], int left, int mid, int right) {
    // TODO: implement merge operation

    int i = left;
    int j = mid + 1;
    int temp[right + 1];
    int idx = 0;

    while (i <= mid && j <= right){
        if (arr[i] < arr[j]){
            temp[idx] = arr[i];
            i++;
        }
        else{
            temp[idx] = arr[j];
            j++;
        }
        idx++;
    }
    
    if (i > mid){
        while (j <= right){
            temp[idx] = arr[j];
            idx++;
            j++;
        }
    }
    else {
        while (i <= mid){
            temp[idx] = arr[i];
            idx++;
            i++;
        }

    }

    for (int k = 0; k < idx; k++){
        arr[left + k] = temp[k];
    }
}

/*
Hybrid merge sort.
*/
void hybridMergeSort(int arr[], int left, int right, int k) {
    // TODO: implement hybrid merge sort

    int mid = (left + right) / 2;

    if (right - left + 1 <= k){
        insertionSort(arr, left, right);
    }
    else{
        hybridMergeSort(arr, left, mid, k);
        hybridMergeSort(arr, mid + 1, right, k);
        merge(arr, left, mid, right);
    }
    
    
}

int main() {
    int arr[] = {39, 9, 81, 45, 90, 27, 72, 18};
    int size = sizeof(arr) / sizeof(arr[0]);

    /*
    k is the threshold.

    When the current subarray size is less than or equal to k,
    insertion sort should be used.

    You may change k to test different behaviors.
    */
    int k = 3;

    printf("Original array:\n");
    printArray(arr, size);

    hybridMergeSort(arr, 0, size - 1, k);

    printf("Sorted array:\n");
    printArray(arr, size);

    if (isSorted(arr, size)) {
        printf("Result: PASS\n");
    } else {
        printf("Result: FAIL\n");
    }

    return 0;
}