/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y; 
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 256;
    int** result = malloc(sizeof(int*)*256);
    int index = 0;
    // sort
    qsort(nums, numsSize,sizeof(int),cmp);
    

    for (int i = 0; i < numsSize - 2; i++) {
        // skip duplicate i
        if (i > 0 && nums[i] == nums[i-1]) continue; 
        
        int left = i+1;
        int right = numsSize-1;

        while (left < right) { 
            int sum = nums[i] + nums[left] + nums[right];   
            
            if (sum < 0) {
                left++;
            }
            else if(sum > 0) {
                right--;
            }
            else if (sum == 0) {

                // ensure capacity
                if (index == capacity) {
                    capacity *= 2;
                    int** tmp = realloc(result, sizeof(int*) * capacity);
                    if (tmp == NULL) break;
                    result = tmp;
                }

                // store triplet
                result[index] = malloc(sizeof(int) * 3);
                result[index][0] = nums[i];
                result[index][1] = nums[left];
                result[index][2] = nums[right];
                index++;

                // move pointers
                right--;
                left++;

                // skip duplicate right
                while (left < right && nums[right] == nums[right+1]) {
                    right--;
                }

                // skip duplicate left
                while (left < right && nums[left] == nums[left-1]) {
                    left++;
                }
            }
        }
    }

    // column sizes
    *returnColumnSizes = malloc(sizeof(int) * index);
    for (int i = 0; i < index; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    // return sizes
    *returnSize = index;

    return result;
}
