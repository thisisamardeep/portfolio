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
            if nums[i] < nums[i + 1]:
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
                nums[swalpleft] = right
                nums[swalright] = left
            nums[swalpleft + 1::1] = nums[swalpleft + 1::1][::-1]
            return


sd = Solution()
eee = [1, 3, 2]
sd.nextPermutation(eee)
print(eee)