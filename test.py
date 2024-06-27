from typing import List


class Solution:

    def amar(self, nums: List[int], low: int, high: int, target: int):
        while low <= high:
            print(low)
            print(high)

            mid = (low + high) // 2
            if nums[mid] == target:
                return mid
            if target <= nums[mid]:
                low = low
                high = mid - 1
            else:
                low = mid + 1
                high = high

        return -1

    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        k = -1  # cutoff point
        for i in range(0, len(nums) - 1, 1):
            if nums[i] > nums[i + 1]:
                k = i
                break
        if k == -1:
            res = self.amar(nums, 0, n - 1, target)
            return res

        res1 = self.amar(nums, k + 1, n - 1, target)
        res2 = self.amar(nums, 0, k, target)

        if res1 == -1 and res2 == -1:
            return -1
        elif res1 != -1:
            return res1
        elif res2 != -1:
            return res2


sd = Solution()

res = sd.search([1], 1)
print(res)
