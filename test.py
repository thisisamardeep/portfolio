from typing import List


class Solution:
    def __init__(self):
        self.result = []

    def amar(self, nums: List[int], curr_index: int, temp: List[int]):

        # print(curr_index)
        if curr_index >= len(nums):
            return

        # if curr_index == len(nums) - 1:
        #     pass
        temp.append(curr_index)
        for i in range(1, nums[curr_index] + 1, 1):
            temp_index = curr_index + i
            self.amar(nums, temp_index, temp)
        if curr_index == len(nums) - 1:
            print(temp)
            self.result.append(temp)
        # print(temp)
        temp.pop()

    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        if len(nums) == 2:
            return 1
        temp = []
        self.amar(nums, 0, temp)
        return 333


df = Solution()
nums = [2, 3, 1, 1, 4]
# nums = [1, 2, 0, 1]
# nums = [1, 2, 3]
res = df.jump(nums=nums)

print(res)
