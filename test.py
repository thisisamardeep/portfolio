from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        i = 0
        while i < len(nums):
            canPass = False
            if nums[i] == 0:
                if i == len(nums) - 1:
                    canPass = True
                else:
                    j = 0
                    while j < i:
                        if i - j < nums[j]:
                            canPass = True
                            break
                        j = j + 1
                if canPass:
                    i = i + 1
                else:
                    break
            else:
                i = i + 1

        if i == len(nums):
            return True
        else:
            return False


sd = Solution()
# nums = [3, 2, 1, 0, 4]
# nums = [2, 3, 1, 1, 4]
nums = [2, 0]
res = sd.canJump(nums=nums)
print(res)
