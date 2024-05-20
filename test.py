from typing import List


class Solution:

    def amar(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]], u: int,
             v: int) -> List[int]:
        flag = -1
        curr = set()
        while True:
            for temp in prerequisites:
                print(344)
                if temp[1] == v:
                    flag = 0
                    curr.add(temp[0])
                else:
                    pass
            if flag == 0 and :
                flag = -1
                continue
            else:
                break
        ER = 45
        return [3, 4]

    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[
        bool]:
        err = self.amar(numCourses=2, prerequisites=[[1, 0]], queries=[[0, 1], [1, 0]], u=1, v=0)
        resultDict = {}
        return None


df1 = Solution()

res = df1.checkIfPrerequisite(numCourses=2, prerequisites=[[1, 0]], queries=[[0, 1], [1, 0]])

print(res)
