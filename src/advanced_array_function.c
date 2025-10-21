#include <limits.h>
#include <stdlib.h>


int max_subarray_sum(int* nums, int size) {
    if (size == 0) return 0;
    
    int max_sum = nums[0];
    int current_sum = nums[0];
    
    for (int i = 1; i < size; i++) {
        if (nums[i] > current_sum + nums[i]) {
            current_sum = nums[i];
        } else {
            current_sum = current_sum + nums[i];
        }
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    return max_sum;
}


int length_of_lis(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int max_length = 1;
    int current_length = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
            }
        } else {
            current_length = 1;
        }
    }
    
    return max_length;
}


int compare_intervals(const void* a, const void* b) {
    int* interval_a = (int*)a;
    int* interval_b = (int*)b;
    return interval_a[0] - interval_b[0];
}


int* merge(int* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    
    int** intervals_copy = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++) {
        intervals_copy[i] = (int*)malloc(2 * sizeof(int));
        intervals_copy[i][0] = intervals[i * 2];
        intervals_copy[i][1] = intervals[i * 2 + 1];
    }
    
    
    qsort(intervals_copy, intervalsSize, sizeof(int*), compare_intervals);
    
    
    int** result_temp = (int**)malloc(intervalsSize * sizeof(int*));
    int result_count = 0;
    
    
    result_temp[result_count] = (int*)malloc(2 * sizeof(int));
    result_temp[result_count][0] = intervals_copy[0][0];
    result_temp[result_count][1] = intervals_copy[0][1];
    result_count++;
    
    
    for (int i = 1; i < intervalsSize; i++) {
        int* last_interval = result_temp[result_count - 1];
        int* current_interval = intervals_copy[i];
        
        if (current_interval[0] <= last_interval[1]) {
            if (current_interval[1] > last_interval[1]) {
                last_interval[1] = current_interval[1];
            }
        } else {
            result_temp[result_count] = (int*)malloc(2 * sizeof(int));
            result_temp[result_count][0] = current_interval[0];
            result_temp[result_count][1] = current_interval[1];
            result_count++;
        }
    }
    
    
    int* result = (int*)malloc(result_count * 2 * sizeof(int));
    for (int i = 0; i < result_count; i++) {
        result[i * 2] = result_temp[i][0];
        result[i * 2 + 1] = result_temp[i][1];
    }
    
    *returnSize = result_count * 2;
    
    
    for (int i = 0; i < intervalsSize; i++) {
        free(intervals_copy[i]);
    }
    free(intervals_copy);
    
    for (int i = 0; i < result_count; i++) {
        free(result_temp[i]);
    }
    free(result_temp);
    
    return result;
}
