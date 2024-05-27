from typing import List, Set

from recviz import recviz


# we assume that before the call the curr index has not bee processed.

class Solution:
    def __init__(self):
        self.max_size = 0

    @recviz
    def amar(self, s: str, partial: List[str], final_result: Set[str], curr_index: int, left_count: int,
             right_count: int):
        if right_count > left_count:
            return
        if curr_index >= len(s):
            if left_count == right_count:
                final_result.add(''.join(partial))
                self.max_size = max(self.max_size, len(partial))

            return
        if s[curr_index] == "(":
            partial.append(s[curr_index])
            self.amar(s, partial, final_result, curr_index + 1, left_count + 1, right_count)
            partial.pop()
            self.amar(s, partial, final_result, curr_index + 1, left_count, right_count)
        elif s[curr_index] == ")":
            partial.append(s[curr_index])
            self.amar(s, partial, final_result, curr_index + 1, left_count, right_count + 1)
            partial.pop()
            self.amar(s, partial, final_result, curr_index + 1, left_count, right_count)
        else:
            partial.append(s[curr_index])
            self.amar(s, partial, final_result, curr_index + 1, left_count, right_count)
            partial.pop()

        pass

    def removeInvalidParentheses(self, s: str) -> List[str]:
        partial = []
        final_result = set()
        curr_index = 0
        self.amar(s, partial, final_result, curr_index, 0, 0)

        final_result_list = []
        for i in final_result:
            if len(i) == self.max_size:
                final_result_list.append(i)

        return final_result_list
        pass


er = Solution()

# sss = "(a)"
# sss = "()())()"
sss = "(a)())()"
# sss = ")("
res = er.removeInvalidParentheses(sss)

# print(res)
