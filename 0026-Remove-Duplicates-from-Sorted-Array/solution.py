class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        idx = 0
        numsSize = len(nums)
        for i in range(numsSize):
            if nums[idx] != nums[i]:
                idx += 1
                nums[idx] = nums[i]

        return idx+1
        
