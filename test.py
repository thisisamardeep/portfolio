from typing import List


class Solution:
    def check(self, piles: List[int], h: int, k: int) -> bool:
        res = 0
        for i in range(0, len(piles), 1):
            r = piles[i] % k
            if r == 0:
                pass
            else:
                res = res + 1
            d = piles[i] // k
            res = res + d
        if res <= h:
            return True

        return False

    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        low = 1
        high = piles[0]
        for i in range(0, len(piles), 1):
            high = max(high, piles[i])

        if self.check(piles, h, 1) is True and self.check(piles, h, 2) is False:
            return 1
        while low < high:
            mid = (low + high) // 2
            if (
                    self.check(piles, h, low) is True
            ):
                return low

            if (
                    self.check(piles, h, low) is False
                    and self.check(piles, h, low + 1) is True
            ):
                return low + 1
            if (
                    self.check(piles, h, high) is True
                    and self.check(piles, h, high - 1) is False
            ):
                return high
            if (
                    self.check(piles, h, mid) is False
                    and self.check(piles, h, mid + 1) is True
            ):
                return mid + 1
            if (
                    self.check(piles, h, mid) is True
                    and mid - 1 > 0
                    and self.check(piles, h, mid - 1) is False
            ):
                return mid

            if self.check(piles, h, mid) is False:
                low = mid + 1
            elif self.check(piles, h, mid) is True:
                high = mid


d = Solution()

resss = d.minEatingSpeed([312884470], 968709470)
print(resss)
