from typing import List


class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        pop_array = [0] * 2051
        max_year = 0
        max_pop = 0
        for i in range(0, len(logs), 1):
            for j in range(logs[i][0], logs[i][1], 1):
                pop_array[j] = pop_array[j] + 1
                if max_pop < pop_array[logs[i][0]]:
                    max_year = logs[i][0]
                    max_pop = pop_array[logs[i][0]]
                elif max_pop == pop_array[logs[i][0]]:
                    if max_year > logs[i][0]:
                        max_year = logs[i][0]
                else:
                    pass

        return max_year


er = Solution()
e4 = [[1993, 1999], [2000, 2010]]
eeee = er.maximumPopulation(e4)

e222 = [4] * 3
e222 = [4] * 3

print(eeee)
