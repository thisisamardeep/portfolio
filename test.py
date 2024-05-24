from typing import List

from recviz import recviz


class Solution:
    def __init__(self):
        self.result = 9999999
        self.jumps = 0

    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        if len(nums) == 2:
            return 1
        jumps = 0
        start_index = 0
        end_index = 0
        new_end_index = 0
        new_start_index = 0



        while True:
            if new_end_index == len(nums) - 1:
                break
            new_start_index = min(end_index + 1, len(nums) - 1)
            for i in range(start_index, end_index + 1, 1):
                new_end_index = max(new_end_index, nums[i] + i)
            new_end_index = min(new_end_index, len(nums) - 1)
            jumps = jumps + 1
            start_index = new_start_index
            end_index = new_end_index

        return jumps


df = Solution()
# nums = [2, 3, 1, 1, 4]
# nums = [1, 2, 0, 1]
nums = [1, 2, 3, 1, 1, 1, 1, 1, 1, 1]
res = df.jump(nums=nums)

print(res)
