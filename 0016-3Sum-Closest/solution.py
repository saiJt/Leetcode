class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        
        # sort
        nums.sort()

        # initialize best sum with a valid combination
        best = nums[0] + nums[1] + nums[2]

        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1

            while (left < right):
                sum = nums[i] + nums[left] + nums[right]

                # update closest sum
                if abs(target - best) > abs(target - sum):
                    best = sum
                
                # exact match
                if target == sum:
                    return target
                elif sum < target:
                    left += 1
                else:
                    right -= 1
                
        return best

