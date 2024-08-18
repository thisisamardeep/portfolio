class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:

        new_list = []
        leftminusright = 0
        for i in s:
            if i == "(":
                leftminusright = leftminusright + 1
                new_list.append(i)
            elif i == ")":
                if leftminusright == 0:
                    pass
                else:
                    leftminusright = leftminusright - 1
                    new_list.append(i)
            else:
                new_list.append(i)
        new_list_second = []
        secondminusleft = 0

        for i in range(-1, -1 * len(new_list) - 1, -1):
            if new_list[i] == ")":
                secondminusleft = secondminusleft + 1
                new_list_second.insert(0, new_list[i])
            elif new_list[i] == "(":
                if secondminusleft == 0:
                    pass
                else:
                    secondminusleft = secondminusleft - 1
                    new_list_second.insert(0, new_list[i])
            else:
                new_list_second.insert(0, new_list[i])
        return "".join(new_list_second)


dff = Solution()

res = dff.minRemoveToMakeValid("lee(t(c)o)de)")
print(res)
