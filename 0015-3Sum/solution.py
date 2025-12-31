class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        result = []

        # sort
        nums.sort()

        for i in range(len(nums) -2):
            # skip duplicate i
            if i > 0 and nums[i] == nums[i-1]: 
                continue
            
            left = i+1
            right = len(nums)-1

            while left < right:
                sum = nums[i] + nums[left] + nums[right]

                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                elif sum == 0:
                    # store triplet
                    result.append([nums[i], nums[left], nums[right]])
                    
                    # move pointers
                    right -= 1
                    left += 1

                    # skip duplicate left
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                    
                    # skip duplicate right
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                
        return result

