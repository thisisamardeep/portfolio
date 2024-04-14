from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        my_dict = {}
        maj_element = 0
        maj_element_count = 0

        for i in range(0, len(nums), 1):
            if nums[i] in my_dict:

                my_dict[nums[i]] = my_dict[nums[i]] + 1
                if maj_element_count < my_dict[nums[i]]:
                    maj_element_count = my_dict[nums[i]]
                    maj_element = nums[i]
            else:
                my_dict[nums[i]] = 1

        return maj_element


sd = Solution()
nums = [2, 2, 1, 1, 1, 2, 2]
# nums = [3, 2, 3]
er = sd.majorityElement(nums)

print(er)
