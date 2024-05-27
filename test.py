from typing import List

from recviz import recviz


class Solution:
    # @recviz
    def myrec(self, n: int, left_used: int, right_used: int, partial_result: str, result: List[str],
              ):
        pass
        if left_used > n or right_used > n:
            return
        if left_used == n and right_used == n:
            result.append(partial_result)
            return

        if right_used < left_used:
            self.myrec(n, left_used + 1, right_used, partial_result + "(", result)
            self.myrec(n, left_used, right_used + 1, partial_result + ")", result)
        else:
            pass

    def generateParenthesis(self, n: int) -> List[str]:
        partial_result: str = "("
        result: List[str] = []
        curr_index = 0
        if n == 0:
            return []
        self.myrec(n, 1, 0, partial_result, result)
        return result


df = Solution()
err = df.generateParenthesis(3)

print(err)
