from typing import List


class Solution:
    def dfs(self, nums: List[int]) -> List:
        if len(nums) == 1:
            return [nums[0], 0]
        if len(nums) > 1:
            first = nums[0: len(nums) - 1: 1]
            second = nums[len(nums) - 1: len(nums):1]
            temp = self.dfs(first)
            withres = second[0] + temp[1]
            without = max(temp[0], temp[1])
            return [withres, without]

    def rob(self, nums: List[int]) -> int:
        res = self.dfs(nums=nums)
        return max(res[0], res[1])


sd = Solution()
# res = sd.rob([1, 2, 3, 1])
res = sd.rob([2, 7, 9, 3, 1])
print(res)
