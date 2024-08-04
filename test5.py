from typing import List


class Solution:

    def amar(self, bloomDay: List[int], m: int, k: int, test_days: int):
        res = [0] * len(bloomDay)

        for i in range(0, len(bloomDay), 1):
            if bloomDay[i] <= test_days:
                res[i] = 1
            else:
                pass

        max_count = 0
        my_temp_stack = []
        for i in range(0, len(res), 1):
            if res[i] == 1:
                my_temp_stack.append(1)
                if len(my_temp_stack) >= k:
                    max_count = max_count + 1
                    my_temp_stack.clear()
            else:
                my_temp_stack.clear()

        if max_count >= m:
            return True
        else:
            return False

    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m * k > len(bloomDay):
            return -1

        high = bloomDay[0]
        for i in range(0, len(bloomDay), 1):
            high = max(high, bloomDay[i])

        low = 1
        while low <= high:
            mid = (low + high) // 2

            if self.amar(bloomDay, m, k, low) is True:
                return low
            if (
                    self.amar(bloomDay, m, k, low) is False
                    and self.amar(bloomDay, m, k, low + 1) is True
            ):
                return low + 1
            if (
                    self.amar(bloomDay, m, k, high) is True
                    and self.amar(bloomDay, m, k, high - 1) is False
            ):
                return high
            if (
                    self.amar(bloomDay, m, k, mid) is True
                    and self.amar(bloomDay, m, k, mid - 1) is False
            ):
                return mid
            if (
                    self.amar(bloomDay, m, k, mid) is False
                    and self.amar(bloomDay, m, k, mid + 1) is True
            ):
                return mid + 1
            if self.amar(bloomDay, m, k, mid) is False:
                low = mid
            else:
                high = mid


sf = Solution()

res = sf.minDays([1, 1, 1, 1], 3, 1)
print(res)
