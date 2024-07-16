from typing import List

"""
We take 2 index low and high.
Low is the starting index and high is the max index.
Now we dont know how may bianry slipts we need to do so 
we rul a loop till low < hoigh


"""


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        low = 0
        high = len(nums) - 1
        mid = 0

        while low < high:

            mid = (low + high) // 2

            if mid == low and low == 0:
                return nums[low]
            if mid == low and high == 0:
                return nums[high]

            if nums[mid] != nums[mid - 1] and nums[mid] != nums[mid + 1]:
                return mid

            if mid % 2 == 0:
                if nums[mid] == nums[mid + 1]:
                    low = mid
                elif nums[mid] == nums[mid - 1]:
                    high = mid
            elif mid % 2 == 1:
                if nums[mid] == nums[mid + 1]:
                    high = mid
                elif nums[mid] == nums[mid - 1]:
                    low = mid

        return mid


nums = [1, 2, 2, 3, 3]

sd = Solution()

res = sd.singleNonDuplicate(nums=nums)
print(res)
