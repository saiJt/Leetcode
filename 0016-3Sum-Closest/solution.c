int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y); // overflow-safe
}

int threeSumClosest(int* nums, int numsSize, int target) {

    // sort
    qsort(nums, numsSize,sizeof(int),cmp);
    
    // initialize best sum with a valid combination
    int max = nums[0] + nums[1] + nums[numsSize-1];

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) { 
            int sum = nums[i] + nums[left] + nums[right];   
            
            // update closest sum
            if (abs(target - max) > abs(target - sum)) {
                max = sum;
            }

            // exact match
            if (target - sum == 0) {
                return target;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return max;
}
