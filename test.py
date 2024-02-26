from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return None
        swalpleft = -1
        swalright = -1
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] > nums[i + 1]:
                swalpleft = i
                break
        if swalpleft == -1:
            nums.reverse()
            return
        else:
            for j in range(len(nums) - 1, swalpleft, -1):
                if nums[j] > nums[swalpleft]:
                    swalright = j
                    break
            if swalright == -1:
                pass
            else:
                left = nums[swalpleft]
                right = nums[swalright]
                nums[swalpleft] = left
                nums[swalright] = right

            leftseg = nums[0: swalpleft + 1: 1]
            rightseg = nums[swalpleft + 1:: 1]
            rightseg.reverse()
            nums = leftseg + rightseg
            return


sd = Solution()
nums = [1, 2, 3, 4]
print(id(nums))
sd.nextPermutation(nums)
print(nums)
