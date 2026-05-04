/*
Question 5: Selection Sort

Description:
Implement selection sort for an integer array.

Selection sort repeatedly finds the smallest element from the unsorted
portion of the array and swaps it with the first element of the unsorted
portion.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
- Do not use any built-in sorting function.
*/

void selectionSort(int arr[], int size) {
    // TODO: implement selection sort
    int smallest = arr[0];
    int temp = 0;
    int smallest_index = 0;

    for (int j = 0; j < size; j++){
        smallest = arr[j];
        smallest_index = j;
        for (int i = j; i < size; i++) {
            if (arr[i] < smallest){
                smallest = arr[i];
                smallest_index = i;
            }
        }

        temp = arr[j];
        arr[j] = smallest;
        arr[smallest_index] = temp;
        smallest_index = 0;

    }
    (void)arr;
    (void)size;
}

