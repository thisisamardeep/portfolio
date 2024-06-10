from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        temp_sum = 0
        max_difference = 200000
        final_sum = 0
        nums.sort()
        for i in range(0, len(nums) - 2, 1):
            first_pointer = i + 1
            second_pointer = len(nums) - 1
            while first_pointer < second_pointer:
                temp_sum = nums[i] + nums[first_pointer] + nums[second_pointer]
                if temp_sum >= target:
                    difference = temp_sum - target
                else:
                    difference = target - temp_sum
                if difference <= max_difference:
                    max_difference = difference
                    final_sum = temp_sum
                if difference == 0:
                    return final_sum
                if temp_sum >= target:
                    second_pointer = second_pointer - 1
                else:
                    first_pointer = first_pointer + 1
        return final_sum

# 0 3 5
er = [-5, -5, -4, 0, 0, 3, 3, 4, 5]
# print(er.sort())
# print(er)
s = Solution()

res = s.threeSumClosest(er, -2)
print(res)
