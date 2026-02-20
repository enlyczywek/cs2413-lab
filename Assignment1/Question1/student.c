#include "Student.h"

//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

 // TODO: implement
 
 (void)nums1Size;
 (void)nums2Size;

 int j = m - 1;
 int k = n - 1;

 for (int i = m + n - 1; i > j; i--) {   
     if (m == 0) {
         for (int l = n-1; l >= 0; l--) {
             nums1[l] = nums2[l];
         }
         break;
     }
     if (nums1[j] >= nums2[k]) {
         nums1[j + k + 1] = nums1[j];
         j--;
     }
     else if (nums1[j] <= nums2[k]) {
         nums1[j + k + 1] = nums2[k];
         k--;
     }
  }

}
