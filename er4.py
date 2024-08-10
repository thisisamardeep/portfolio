class Solution:

    def possiblyEquals(self, s1: str, s2: str) -> bool:
        pass
        s1_list = []

        i = 0
        while i < len(s1):
            if s1[i].isnumeric() is True and i + 1 < len(s1) and s1[i + 1].isnumeric() is True and i + 2 < len(s1) and \
                    s1[i + 2].isnumeric() is True:

                temp = [int(s1[i]), int(s1[i + 1]), int(s1[i + 2]), int(s1[i:i + 2:1]), int(s1[i:i + 3:1]),
                        int(s1[i + 1:i + 3:1])]
                print(temp)
                i = i + 3

            elif (s1[i].isnumeric() is True and i + 1 < len(s1) and s1[i + 1].isnumeric() is True
                  and ((i + 2 < len(s1) and s1[i + 2].isnumeric() is False)
                       or (i + 2 >= len(s1)))):
                temp = [int(s1[i]), int(s1[i + 1]), int(s1[i:i + 2:1])
                        ]
                print(temp)
                i = i + 2
            else:
                i = i + 1


ss = Solution()

res = ss.possiblyEquals("l123e", "44")
print(res)
