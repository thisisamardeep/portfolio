from typing import List


class Solution:
    def dfs(self, index: int, nums: List[int]) -> List:
        if index == len(nums) - 1:
            return [nums[-1], 0]
        else:
            temp = self.dfs(index + 1, nums)
            withcal = nums[index] + temp[1]
            withoutcal = max(temp[1], temp[0])
            return [withcal, withoutcal]

    def rob(self, nums: List[int]) -> int:
        res = self.dfs(0, nums)
        return max(res[0], res[1])


err = Solution()

res = err.rob([1, 2, 3, 1])
