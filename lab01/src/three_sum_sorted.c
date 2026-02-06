#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++){
               if ((nums[i] + nums[j] == (-1*nums[k])) && (i < j) && (j < k)){
                *out_i = i;
                *out_j = j;
                *out_k = k;
                return 1;
                } 
            }            
        }
    }
    return 0;
}
