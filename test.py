from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        res = True
        reachable = 0
        for i in range(0, len(nums), 1):
            if reachable < i:
                res = False
                break
            else:
                reachable = max(reachable, i + nums[i])
        return res


sd = Solution()
# nums = [3, 2, 1, 0, 4]
# nums = [2, 3, 1, 1, 4]
nums = [2, 0]
res = sd.canJump(nums=nums)
print(res)
