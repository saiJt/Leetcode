/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y); // overflow-safe
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity = 256;
    int** result = malloc(sizeof(int*) * capacity);
    int index = 0;

    // sort
    qsort(nums, numsSize, sizeof(int), cmp);


    for (int i = 0; i < numsSize - 3; i++) {
        // skip duplicate i
        if (i > 0 && nums[i] == nums[i-1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            // skip duplicate j
            if (j > i + 1 && nums[j] == nums[j-1]) continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }

                else {
                    // ensure capacity
                    if (index == capacity) {
                        capacity *= 2;
                        int** tmp = realloc(result, sizeof(int*) * capacity);
                        if(tmp == NULL) break;
                        result = tmp;
                    }

                    // store four variables
                    result[index] = malloc(sizeof(int) * 4);
                    result[index][0] = nums[i];
                    result[index][1] = nums[j];
                    result[index][2] = nums[left];
                    result[index][3] = nums[right];
                    index++;

                    // move pointers
                    right--;
                    left++;

                    // skip duplicate left
                    while (left < right && nums[right] == nums[right+1]) {
                        right--;
                    }

                    while (left <right && nums[left] == nums[left-1]) {
                        left++;
                    }
                }
            }
        }
    }

    // column sizes
    *returnColumnSizes = malloc(sizeof(int) * index);
    for (int i = 0; i< index; i++){
        (*returnColumnSizes)[i] = 4;
    }

    //return sizes
    *returnSize = index;

    return result;
    
}
