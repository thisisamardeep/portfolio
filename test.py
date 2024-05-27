from typing import List

from recviz import recviz


class Solution:
    # @recviz
    def myrec(self, n: int, left_used: int, right_used: int, partial_result: List[str], result: List[str],
              ):
        print(id(partial_result))
        if left_used > n or right_used > n:
            return
        if left_used == n and right_used == n:
            result.append(''.join(partial_result))
            return

        if right_used < left_used:
            partial_result.append("(")
            self.myrec(n, left_used + 1, right_used, partial_result, result)
            partial_result.pop()
            partial_result.append(")")
            self.myrec(n, left_used, right_used + 1, partial_result, result)
            partial_result.pop()
        elif right_used == left_used:
            partial_result.append("(")
            self.myrec(n, left_used + 1, right_used, partial_result, result)
            partial_result.pop()

    def generateParenthesis(self, n: int) -> List[str]:
        partial_result: List[str] = ["("]
        result: List[str] = []
        if n == 0:
            return []
        self.myrec(n, 1, 0, partial_result, result)
        return result


df = Solution()
err = df.generateParenthesis(3)

print(err)
