/*
Question 3: Quick Sort

Description:
Implement quick sort to sort an integer array in ascending order.

Quick sort is a divide-and-conquer algorithm:
1. Choose a pivot element.
2. Partition the array so that elements smaller than or equal to
   the pivot come before it, and elements greater than the pivot
   come after it.
3. Recursively sort the left and right parts.

You should implement:

    void quickSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void quickSortHelper(int arr[], int low, int high);
    int partition(int arr[], int low, int high);

For simplicity, you may use the last element as the pivot.

Example:
Input:  [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]

Notes:
- If the array is empty or has only one element, do nothing.
- The sorting should be done in ascending order.
*/ 


int partition(int arr[], int low, int high) {

    // Initialize pivot to be the first element
    int pivot = arr[low];
    int i = low;
    int j = high;
    int temp = 0;

    while (i < j) {

        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSortHelper(int arr[], int low, int high) {
    // TODO: implement quick sort
    if (low < high){
        int partition_value = partition(arr, low, high);
        quickSortHelper(arr, low, partition_value - 1);
        quickSortHelper(arr, partition_value + 1, high);
    }
}

void quickSort(int arr[], int size) {
    
    quickSortHelper(arr, 0, size - 1);
    //(void)arr;
    //(void)size;
}

